#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

class QmaskSovereignReserveEngine {
private:
    const double baseQsrRewardPerBlock = 1.00; // Base baseline payout: 1.00 QSR per block
    const double minimumQmkCollateral = 5000.00; // Must hold a minimum of 5,000 QMK to enter this tier

public:
    // 👑 1. SOVEREIGN GATEKEEPER: Verifies strict collateral and hardware simulation proofs
    bool VerifyHighTierEligibility(double userQmkCollateral, bool passesHardwareLatticeSimulation) {
        std::cout << "🔍 [Sovereign Auditor] Evaluating high-tier node eligibility requirements...\n";
        
        if (userQmkCollateral < minimumQmkCollateral) {
            std::cout << "❌ [ACCESS DENIED] Insufficient QMK collateral locked. Standard yield tier only.\n";
            return false;
        }
        if (!passesHardwareLatticeSimulation) {
            std::cout << "❌ [ACCESS DENIED] Node failed the active background Lattice Matrix data computation check.\n";
            return false;
        }

        std::cout << "👑 [ACCESS GRANTED] High-Tier Sovereign validation status unlocked successfully!\n";
        return true;
    }

    // ⚡ 2. ZEPHYR-INSPIRED ATH MULTIPLIER: Escalates rewards based on network growth conditions
    double CalculateSovereignQsrReward(bool isEligible, double currentNetworkDifficulty, bool isMarketAtAllTimeHigh) {
        if (!isEligible) return 0.0;

        double activeRewardMultiplier = 1.0;

        // If the ecosystem hits an ATH condition, scale the rewards up exponentially
        if (isMarketAtAllTimeHigh) {
            std::cout << "📈 [ALL-TIME HIGH CAUGHT] Network activity surge detected! Triggering leverage multipliers.\n";
            activeRewardMultiplier = 5.0; // 5x Payout expansion matrix mode activated
        } else {
            // Standard condition scaling based on structural difficulty parameters
            activeRewardMultiplier = 1.0 + (currentNetworkDifficulty / 100000.0);
        }

        double finalQsrMint = baseQsrRewardPerBlock * activeRewardMultiplier;
        std::cout << "🪙 [QSR Mint Engine] Natively generating +" << std::fixed << std::setprecision(4) 
                  << finalQsrMint << " QSR tokens straight to Sovereign Node Vault.\n";
        return finalQsrMint;
    }
};

int main() {
    std::cout << "👑 =========================================================\n";
    std::cout << "👑 INITIALIZING ALPHA-0 HIGH-TIER SOVEREIGN RESERVE ENGINE  \n";
    std::cout << "👑 =========================================================\n\n";

    QmaskSovereignReserveEngine reserveEngine;
    double currentDifficulty = 14500.00;

    // CASE A: A standard user attempts to bypass the security wall with low collateral
    bool userA_Eligible = reserveEngine.VerifyHighTierEligibility(1200.00, true);
    reserveEngine.CalculateSovereignQsrReward(userA_Eligible, currentDifficulty, false);
    std::cout << "----------------------------------------------------------------\n\n";

    // CASE B: An elite home miner locks 10,000 QMK, passes the background CPU matrix test, and hits an ATH market surge
    bool userB_Eligible = reserveEngine.VerifyHighTierEligibility(10000.00, true);
    reserveEngine.CalculateSovereignQsrReward(userB_Eligible, currentDifficulty, true);
    std::cout << "----------------------------------------------------------------\n";

    return 0;
}
