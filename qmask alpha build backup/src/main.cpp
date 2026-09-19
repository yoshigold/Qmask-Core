#include <iostream>
#include <string>
#include <vector>
#include "qmask_engine.h"
#include "subsidy.h"
#include "decay.h"
#include "difficulty.h"
#include "network.h"
#include "fees.h"
#include "wallet_store.h"
#include "tx_signer.h"
#include "block_packer.h"
#include "decay_manager.h"
#include "block_logger.h"
#include "rpc_server.h" // Hook in our new network RPC engine

int main() {
    std::cout << "👑 =========================================================\n";
    std::cout << "👑    LAUNCHING FULL UNIFIED QMASK (QMK) BLOCKCHAIN CORE    \n";
    std::cout << "👑 =========================================================\n\n";

    // 1. Initialize all subengines into a single processing memory layer
    QmaskEngine cryptoEngine;
    QmaskSubsidyEngine economyEngine;
    QmaskDecayEngine decayEngine;
    QmaskDifficultyRegulator asertEngine;
    QmaskNetworkNode p2pNode;
    QmaskFeeManager feeEngine;
    QmaskWalletStore walletStorage;
    QmaskTxSigner txSigner;
    QmaskBlockPacker blockPacker;
    QmaskDecayManager decayManager;
    QmaskBlockLogger blockLogger;
    QmaskRpcServer rpcServer;

    std::cout << "[Core] All 12 Post-Quantum Subsystems Active and Linked.\n";
    std::cout << "----------------------------------------------------------------\n";

    // 2. Fire up the network node API framework interface channels
    rpcServer.LaunchRpcListener();
    std::cout << "\n";

    // 3. Simulate an external wallet query request incoming from the network API
    std::string apiQueryResponse = rpcServer.ProcessIncomingRpcRequest("getbalance");
    std::cout << "📡 [RPC Response]: " << apiQueryResponse << "\n\n";

    // 4. Simulate Local Wallet Profile Setup
    std::string userProfile = "yoshiki_main";
    std::string mockQuantumAddress = "qmpNdwz8p_quantum_safe_dilithium_coordinates_abc123";
    std::string freshSeed = walletStorage.GenerateQuantumSeed();
    walletStorage.SaveWalletToDisk(userProfile, mockQuantumAddress, freshSeed);

    // 5. Simulate Outbound Transaction Generation
    std::string targetDestination = "qmpDestinationAddress789xyz";
    double transferAmount = 15.75;
    std::string generatedTxSignature = txSigner.GenerateLightweightSignature(freshSeed, targetDestination, transferAmount);
    std::string txData = "Yoshiki_sends_" + targetDestination + "_" + std::to_string(transferAmount) + "_QMK";

    // 6. Blind Mempool Mask
    std::vector<unsigned char> localNoise = cryptoEngine.ReadElectronNoise(32);
    std::string maskedMempoolHash = cryptoEngine.CreateMaskedCommitment(txData, generatedTxSignature, localNoise);

    // 7. Simulate Mining Processing (Block #100,000)
    int targetBlockHeight = 100000;
    long long measuredBlockTime = 5;
    double startingDifficulty = 5000.00;
    double rawMiningThreads = 32.0;

    std::cout << "⛏️  [Consensus] Verifying Block Height #" << targetBlockHeight << "...\n";
    double throttledPower = p2pNode.CalculateEffectivePower(rawMiningThreads);
    double nextDifficulty = asertEngine.CalculateNextDifficulty(startingDifficulty, measuredBlockTime);
    double activeBlockReward = economyEngine.GetCurrentBlockReward(targetBlockHeight);

    // 8. Group and Serialize Transactions into Block Data format
    std::string mockPreviousHash = "000000001bea891e0000000000000000";
    std::vector<std::string> blockTxQueue;
    blockTxQueue.push_back(maskedMempoolHash);
    std::string packedBlockRoot = blockPacker.PackBlockData(targetBlockHeight, mockPreviousHash, blockTxQueue);

    // 9. Run the Ledger Inactivity State Audit
    decayManager.AuditLedgerInactivity("ghost_wallet_abc123", 1000.00, 4500);

    // 10. Split the fees across the ecosystem
    double blockFeesToProcess = 8.50;
    feeEngine.DistributeFees(blockFeesToProcess);
    double totalTokensDestroyed = (blockFeesToProcess * 0.40) + 826.3021;

    // 11. Write the Final Block directly to the Hard Drive Ledger Database
    std::cout << "💾 [Ledger] Committing block payload to permanent storage file...\n";
    blockLogger.WriteBlockToLedger(targetBlockHeight, packedBlockRoot, activeBlockReward, totalTokensDestroyed);

    std::cout << "================================================================\n";
    std::cout << "🎉 [Success] Block #" << targetBlockHeight << " sealed cleanly into the unified Qmask ledger!\n";
    std::cout << "================================================================\n";

    return 0;
}
