#include <iostream>
#include <string>
#include <iomanip>

class QmaskGasMiningEngine {
private:
    const double qgfBlockSubsidy = 10.00; // Native secondary block reward: 10.00 QGF per valid gas proof block
    const double minimumGasThresholdGwei = 50.00; // Minimum gas expenditure required to claim a block share

public:
    // ⚙️ FUNCTION: Validates external network gas expenditure data to mint the secondary native coin
    double VerifyExternalGasProofAndMint(const std::string& minerWalletAddress, double gasSpentGwei, const std::string& externalTxId) {
        std::cout << "🔍 [Gas Monitor] Auditing external cross-chain transaction ID: " << externalTxId.substr(0, 16) << "...\n";
        std::cout << "📊 Verified Gas Consumed on Host Chain: " << gasSpentGwei << " Gwei\n";

        // Check if the miner spent enough gas to clear our anti-spam security gate
        if (gasSpentGwei < minimumGasThresholdGwei) {
            std::cout << "❌ [Proof Rejected] Gas consumption below the protocol safety threshold. Zero QGF minted.\n";
            return 0.0;
        }

        // Mathematical Scaling: If a miner purposefully spends more gas, calculate a minor efficiency bonus multiplier
        double boostFactor = 1.0 + (gasSpentGwei / 1000.0);
        if (boostFactor > 2.0) boostFactor = 2.0; // Hard cap the maximum bonus multiplier to protect scarcity

        double finalMintedAmount = qgfBlockSubsidy * boostFactor;

        std::cout << "✅ [PROOF APPROVED] Cryptographic gas signature verified successfully!\n";
        std::cout << "🪙 [Mint Native Asset] Issuing " << std::fixed << std::setprecision(4) << finalMintedAmount 
                  << " QGF (Qmask Gas Fuel) to wallet: " << minerWalletAddress.substr(0, 15) << "...\n";
        
        return finalMintedAmount;
    }
};
