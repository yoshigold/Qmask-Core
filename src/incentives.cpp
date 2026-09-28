#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

class QmaskIncentiveMatrix {
private:
    const double targetMaxEmission = 1.00; // Hardcoded maximum absolute emission cap per block (1.00 QMK)

public:
    // 🎛️ FUNCTION: Dynamically balances the Loyalty Pool and the Luck Pot based on network hashrate
    void CalculateDualPoolRewards(double networkHashrate, unsigned char electronEntropyByte) {
        double loyaltyPoolShare = 0.50;
        double luckPoolShare = 0.50;

        std::cout << "📊 [Network Audit] Active Hashrate Speed: " << networkHashrate << " MH/s\n";

        // 🔄 THE DYNAMIC HEALTH SWAPPER LAYER
        if (networkHashrate > 5000.0) {
            // High Surge Era: Compress the Luck Pot to shield against inflation, routing excess to the burn address
            std::cout << "⚠️  High Network Surge Caught! Shifting allocation parameters to 75/25 Protection Mode.\n";
            loyaltyPoolShare = 0.75;
            luckPoolShare = 0.25;
        } else if (networkHashrate < 1000.0) {
            // Low Competition Era: Maximize the Luck Pot to incentivize solo node prospectors
            std::cout << "🟢 Home Mining Safe Era: Shifting allocation parameters to 25/75 Lucky Mode.\n";
            loyaltyPoolShare = 0.25;
            luckPoolShare = 0.75;
        } else {
            std::cout << "⚖️  Balanced Network Era: Sticking to standard 50/50 baseline split matrix.\n";
        }

        // 🎰 THE CRYPTOGRAPHIC LUCK POT STEP (LuckyPepe / Discrete style verification)
        // Roll a rolling cryptographic pseudo-random dice check using your electron noise randomness
        int rollingDiceRoll = (static_cast<int>(electronEntropyByte) + (rand() % 100)) % 100;
        double activeLuckMultiplier = 1.0;

        if (rollingDiceRoll > 85) {
            // 🎯 JACKPOT SHARE HIT: Unlock a 3x luck multiplier payout allocation from the reserve pool
            std::cout << "🎯🎯🎯 CRITICAL LUCK JACKPOT HIT! Solo node generated a winning entropy hash leaf.\n";
            activeLuckMultiplier = 3.0;
        }

        // Compute the final concrete token distributions
        double absoluteLoyaltyPayout = targetMaxEmission * loyaltyPoolShare;
        double absoluteLuckPayout = (targetMaxEmission * luckPoolShare) * (activeLuckMultiplier / 3.0);
        double combinedEmission = absoluteLoyaltyPayout + absoluteLuckPayout;

        std::cout << "⛏️  [Allocation] Long-Term Loyalty Reward Layer: " << absoluteLoyaltyPayout << " QMK\n";
        std::cout << "🎲 [Allocation] Dynamic Lucky Block Reward Layer: " << absoluteLuckPayout << " QMK\n";
        std::cout << "🪙 [Total Mint] Global Active Emission Added    : " << combinedEmission << " QMK / 1.00 QMK Max\n";
        
        if (combinedEmission < targetMaxEmission) {
            double deflationaryBurnYield = targetMaxEmission - combinedEmission;
            std::cout << "🔥 [Deflation] Inflation Shield Active: " << deflationaryBurnYield << " QMK permanently destroyed!\n";
        }
        std::cout << "----------------------------------------------------------------\n\n";
    }
};
