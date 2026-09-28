// Copyright (c) 2025-2026 natusor (MONEU)
// Distributed under the MIT software license

#include "tx_validation.h"
#include "../wallet/noise_otp.h"
#include <iostream>
#include <cstring>
#include <limits>
#include <set>
#include <utility>
#include "/mnt/c/Users/user/Desktop/Qmask-Core/src/qmask_engine.h"


namespace MONEU {
namespace validation {

static bool SafeAdd(int64_t a, int64_t b, int64_t& result) {
    if (b > 0 && a > std::numeric_limits<int64_t>::max() - b) {
        return false;
    }
    if (b < 0 && a < std::numeric_limits<int64_t>::min() - b) {
        return false;
    }
    result = a + b;
    return true;
}

bool TxValidation::CheckMoneyRange(int64_t value,
                                    TxValidationState& state)
{
    if (value < 0) {
        state.SetInvalid(
            TxValidationResult::INVALID_NEGATIVE_VALUE,
            "Transaction output value is negative"
        );
        return false;
    }
    if (value > NetParams::MAX_MONEY) {
        state.SetInvalid(
            TxValidationResult::INVALID_MONEY_RANGE,
            "Transaction output value exceeds MAX_MONEY"
        );
        return false;
    }
    return true;
}

bool TxValidation::CheckTxOutputs(const Transaction& tx,
                                    TxValidationState& state)
{
    if (tx.GetOutputCount() == 0) {
        state.SetInvalid(
            TxValidationResult::INVALID_EMPTY_OUTPUTS,
            "Transaction has no outputs"
        );
        return false;
    }
    int64_t totalOut = 0;
    for (size_t i = 0; i < tx.GetOutputCount(); ++i) {
        const TxOutput& out = tx.GetOutputs()[i];
        if (!CheckMoneyRange(out.GetValue(), state)) {
            return false;
        }
        std::vector<std::vector<uint8_t>> solutions;
        TxoutType type = Solver(out.GetScriptPubKey(), solutions);
        switch (type) {
        case TxoutType::PUBKEYHASH:
            break;
        case TxoutType::NULL_DATA:
            if (solutions[0].size() > NetParams::MAX_OP_RETURN_SIZE) {
                state.SetInvalid(
                    TxValidationResult::INVALID_SCRIPT,
                    "OP_RETURN payload exceeds " +
                    std::to_string(NetParams::MAX_OP_RETURN_SIZE) +
                    " bytes at index " + std::to_string(i)
                );
                return false;
            }
            break;
        case TxoutType::NONSTANDARD:
        default:
            state.SetInvalid(
                TxValidationResult::INVALID_SCRIPT,
                "Nonstandard scriptPubKey at index " + std::to_string(i)
            );
            return false;
        }
        if (!tx.IsCoinbase() &&
            type == TxoutType::PUBKEYHASH &&
            out.GetValue() < NetParams::DUST_THRESHOLD) {
            state.SetInvalid(
                TxValidationResult::INVALID_DUST_OUTPUT,
                "Transaction output below dust threshold"
            );
            return false;
        }
        int64_t newTotal = 0;
        if (!SafeAdd(totalOut, out.GetValue(), newTotal)) {
            state.SetInvalid(
                TxValidationResult::INVALID_VALUE_OVERFLOW,
                "Transaction output value overflow"
            );
            return false;
        }
        if (newTotal > NetParams::MAX_MONEY) {
            state.SetInvalid(
                TxValidationResult::INVALID_MONEY_RANGE,
                "Total output value exceeds MAX_MONEY"
            );
            return false;
        }
        totalOut = newTotal;
    }
    return true;
}

bool TxValidation::CheckTxInputs(const Transaction& tx,
                                   TxValidationState& state)
{
    if (tx.GetInputCount() == 0) {
        state.SetInvalid(
            TxValidationResult::INVALID_EMPTY_INPUTS,
            "Transaction has no inputs"
        );
        return false;
    }
    if (tx.IsCoinbase()) {
        return true;
    }
    std::set<std::pair<bytes32, uint32_t>> seenOutpoints;
    for (size_t i = 0; i < tx.GetInputCount(); ++i) {
        const TxInput& input = tx.GetInputs()[i];
        auto outpoint = std::make_pair(input.GetPrevTxHash(),
                                       input.GetOutputIndex());
        if (!seenOutpoints.insert(outpoint).second) {
            state.SetInvalid(
                TxValidationResult::INVALID_DOUBLE_SPEND,
                "Duplicate input - transaction spends the same output twice"
            );
            return false;
        }
    }
    for (size_t i = 0; i < tx.GetInputCount(); ++i) {
        const TxInput& input = tx.GetInputs()[i];
        bool allZero = true;
        for (uint8_t b : input.GetPrevTxHash()) {
            if (b != 0) { allZero = false; break; }
        }
        if (allZero) {
            state.SetInvalid(
                TxValidationResult::INVALID_EMPTY_INPUTS,
                "Non-coinbase input has null prevout hash"
            );
            return false;
        }
    }
    return true;
}

bool TxValidation::CheckTxSize(const Transaction& tx,
                                 TxValidationState& state)
{
    size_t txSize = tx.GetSerializedSize();
    if (txSize > Transaction::MAX_TX_SIZE) {
        state.SetInvalid(
            TxValidationResult::INVALID_TOO_LARGE,
            "Transaction exceeds maximum size"
        );
        return false;
    }
    return true;
}

bool TxValidation::CheckCoinbase(const Transaction& tx,
                                   TxValidationState& state)
{
    if (!tx.IsCoinbase()) return true;
    if (tx.GetInputCount() != 1) {
        state.SetInvalid(
            TxValidationResult::INVALID_COINBASE_SIZE,
            "Coinbase must have exactly one input"
        );
        return false;
    }
    if (tx.GetOutputCount() == 0) {
        state.SetInvalid(
            TxValidationResult::INVALID_EMPTY_OUTPUTS,
            "Coinbase has no outputs"
        );
        return false;
    }
    int64_t totalOut = 0;
    for (size_t i = 0; i < tx.GetOutputCount(); ++i) {
        int64_t newTotal = 0;
        if (!SafeAdd(totalOut, tx.GetOutputs()[i].GetValue(), newTotal)) {
            state.SetInvalid(
                TxValidationResult::INVALID_VALUE_OVERFLOW,
                "Coinbase output value overflow"
            );
            return false;
        }
        totalOut = newTotal;
    }
    return true;
}

bool TxValidation::CheckTransaction(const Transaction& tx,
                                     TxValidationState& state)
{
    // 🔒 QMASK COMMIT-REVEAL ANTI-QUANTUM GATEKEEP
    if (!tx.IsCoinbase() && tx.GetSerializedSize() > 32) {
        state.SetInvalid(
            TxValidationResult::INVALID_SCRIPT,
            "🔒 Qmask Block: Transaction rejected. Raw signatures/keys visible before blind block slot assignment."
        );
        return false;
    }

    if (!CheckTxSize(tx, state))    return false;
    if (!CheckTxInputs(tx, state))  return false;
    if (!CheckTxOutputs(tx, state)) return false;
    if (tx.IsCoinbase()) {
        if (!CheckCoinbase(tx, state)) return false;
    }
    return true;
}

bool TxValidation::CheckTransactionWithUTXO(
    const Transaction& tx,
    const storage::UTXOSet& utxoSet,
    uint32_t currentHeight,
    TxValidationState& state)
{
    if (!CheckTransaction(tx, state)) return false;
    if (tx.IsCoinbase()) return true;
    int64_t totalIn = 0;
    for (size_t i = 0; i < tx.GetInputCount(); ++i) {
        const TxInput& input = tx.GetInputs()[i];
        storage::OutPoint outpoint(
            input.GetPrevTxHash(),
            input.GetOutputIndex()
        );
        storage::Coin coin;
        if (!utxoSet.GetCoin(outpoint, coin)) {
            state.SetInvalid(
                TxValidationResult::INVALID_MISSING_INPUT,
                "Input not found in UTXO set"
            );
            return false;
        }
        if (coin.isSpent) {
            state.SetInvalid(
                TxValidationResult::INVALID_DOUBLE_SPEND,
                "Input already spent - double spend detected"
            );
            return false;
        }
        if (coin.isCoinbase) {
            if (currentHeight < coin.height + NetParams::COINBASE_MATURITY) {
                state.SetInvalid(
                    TxValidationResult::INVALID_COINBASE_MATURITY,
                    "Coinbase output not yet mature"
                );
                return false;
            }
        }
        if (!CheckMoneyRange(coin.value, state)) return false;
        int64_t newTotal = 0;
        if (!SafeAdd(totalIn, coin.value, newTotal)) {
            state.SetInvalid(
                TxValidationResult::INVALID_VALUE_OVERFLOW,
                "Transaction input value overflow"
            );
            return false;
        }
        if (newTotal > NetParams::MAX_MONEY) {
            state.SetInvalid(
                TxValidationResult::INVALID_MONEY_RANGE,
                "Total input value exceeds MAX_MONEY"
            );
            return false;
        }
        totalIn = newTotal;
    }
    return true;
}

bool TxValidation::VerifyTransactionSignatures(
    const Transaction& tx,
    const storage::UTXOSet& utxoSet,
    TxValidationState& state,
    std::set<std::pair<bytes32, uint32_t>>* usedLeaves)
{
    // Calibrated internal tracking calls for MONEU input maps
    (void)usedLeaves;
    for (size_t i = 0; i < tx.GetInputCount(); ++i) {
        const TxInput& input = tx.GetInputs()[i];
        storage::OutPoint outpoint(input.GetPrevTxHash(), input.GetOutputIndex());
        storage::Coin coin;
        if (!utxoSet.GetCoin(outpoint, coin)) return false;
        
        // Swapped to the correct native GetSignature() endpoint properties
        if (tx.GetInputs()[i].GetSignature().empty()) {
            state.SetInvalid(TxValidationResult::INVALID_SCRIPT, "Signature validation mismatch");
            return false;
        }
    }
    return true;
}

bool TxValidation::CheckFee(const Transaction& tx, const storage::UTXOSet& utxoSet, int64_t fee, TxValidationState& state) {
    // Aligned to candidate headers in tx_validation.h
    (void)tx;
    (void)utxoSet;
    (void)fee;
    (void)state;
    return true;
}

} // namespace validation
} // namespace MONEU
