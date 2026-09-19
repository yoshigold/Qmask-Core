#include <iostream>
#include <string>
#include <map>
#include <iomanip>

struct VestingAccount {
    double totalRescuedBalance;
    int blocksElapsedSinceCrash;
    bool initialCoolingLockActive;
    double acceleratedUnlockBonus; // Boosted factor earned via gameplay loops
};

class QmaskMirrorVestingEngine {
private:
    const int coolingPeriodBlocks = 10000; // Simulating roughly 90 days of block times
    const int fullVestingDurationBlocks = 50000; // Roughly 12 months for a complete unlock

public:
    // 🔀 FUNCTION: Evaluates a user's Mirror 1 balance to see how much is liquid vs locked
    double CalculateLiquidSpendableBalance(const std::string& accountWallet, VestingAccount account) {
        std::cout << "🛡️  [Vesting Guard] Auditing Mirror 1 Lifeboat restrictions for: " << accountWallet.substr(0, 16) << "...\n";
        std::cout << "📊 Total Rescued Balance Transferred: " << account.totalRescuedBalance << " M1-Tokens\n";

        // Step 1: Check if the global cooling-off shield is still active
        if (account.blocksElapsedSinceCrash < coolingPeriodBlocks && account.initialCoolingLockActive) {
            std::cout << "🔒 [STATUS: LOCKED] Account sits inside the 90-Day Global Cooling-Off window.\n";
            std::cout << "❌ Spendable Liquid Balance: 0.0000 M1-Tokens (Ecosystem Shock-Absorber Engaged)\n";
            std::cout << "----------------------------------------------------------------\n\n";
            return 0.0;
        }

        // Step 2: Calculate standard linear vesting progress
        int blocksPastCooling = account.blocksElapsedSinceCrash - coolingPeriodBlocks;
        if (blocksPastCooling < 0) blocksPastCooling = 0;

        double vestingProgressRatio = static_cast<double>(blocksPastCooling) / static_cast<double>(fullVestingDurationBlocks);
        if (vestingProgressRatio > 1.0) vestingProgressRatio = 1.0;

        // Step 3: Factor in any gameplay/mining acceleration multipliers
        double totalUnlockedRatio = vestingProgressRatio + account.acceleratedUnlockBonus;
        if (totalUnlockedRatio > 1.0) totalUnlockedRatio = 1.0;

        double liquidSpendable = account.totalRescuedBalance * totalUnlockedRatio;
        double remainingLocked = account.totalRescuedBalance - liquidSpendable;

        std::cout << "🔓 [STATUS: PARTIALLY UNLOCKED] Linear Vesting running smoothly.\n";
        if (account.acceleratedUnlockBonus > 0.0) {
            std::cout << "⚡ Gameplay Acceleration Active! Premium unlock bonus applied: +" << (account.acceleratedUnlockBonus * 100) << "%\n";
        }
        std::cout << "🟢 Spendable Liquid Balance: " << std::fixed << std::setprecision(4) << liquidSpendable << " M1-Tokens\n";
        std::cout << "🔒 Remaining Vested Lock   : " << std::fixed << std::setprecision(4) << remainingLocked << " M1-Tokens\n";
        std::cout << "----------------------------------------------------------------\n\n";
        
        return liquidSpendable;
    }
};
