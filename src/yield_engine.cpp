#include <iostream>
#include <string>
#include <map>
#include <iomanip>

struct StakingPosition {
    double lockedQmkAmount;
    int lockBlockDuration;
    int blocksElapsed;
};

class QmaskYieldEngine {
private:
    const double qgfInterestBaseRate = 0.05; // 5% base annual percentage rate target yield scaling

public:
    // 🔒 1. HOLDER LATTICE-LOCK CONTROLLER: Calculates gas fuel yield payout allocations
    double CalculateStakingYield(const std::string& userWallet, StakingPosition position, double activeBlockFeesCollected) {
        if (position.blocksElapsed < position.lockBlockDuration) {
            std::cout << "⏳ [Yield Engine] Position locked. Blocks remaining: " 
                      << (position.lockBlockDuration - position.blocksElapsed) << "\n";
        }

        // Compute yield: Proportional share of active transaction fees multiplied by duration weight
        double durationMultiplier = 1.0 + (static_cast<double>(position.lockBlockDuration) / 10000.0);
        double calculatedQgfInterest = (position.lockedQmkAmount * qgfInterestBaseRate * durationMultiplier) * (activeBlockFeesCollected / 100.0);

        std::cout << "✨ [YIELD EARNED] Lattice-Lock Active for: " << userWallet.substr(0, 15) << "...\n";
        std::cout << "💼 Locked Reserve: " << position.lockedQmkAmount << " QMK | Term: " << position.lockBlockDuration << " Blocks\n";
        std::cout << "🪙 Interest Payout: Issued +" << std::fixed << std::setprecision(6) << calculatedQgfInterest << " QGF Gas Fuel to holder.\n";
        std::cout << "----------------------------------------------------------------\n";
        return calculatedQgfInterest;
    }

    // 🎮 2. IN-GAME ADVENTURE STAKING ENGINE: Processes monster training gym drops
    void ProcessAdventureStakingTick(const std::string& monsterDnaToken, int hoursInGym) {
        std::cout << "👾 [Adventure Staking] Processing gym telemetry for Beast DNA: [" << monsterDnaToken << "]\n";
        
        int accumulatedXp = hoursInGym * 15;
        double itemDropChance = (hoursInGym * 7) % 100;

        std::cout << "📈 Training Progress: Gained +" << accumulatedXp << " EXP Points.\n";
        if (itemDropChance > 65) {
            std::cout << "🎁 [RARE DROP CAPTURED] Beast uncovered a high-tier cryptographic Capture Capsule file!\n";
        } else {
            std::cout << "📦 Standard Drop: Beast scavenged standard restoration items from the mempool.\n";
        }
        std::cout << "----------------------------------------------------------------\n\n";
    }
};

int main() {
    std::cout << "📊 =========================================================\n";
    std::cout << "📊 INITIALIZING ALPHA-0 MASTER DECENTRALIZED YIELD ENGINE    \n";
    std::cout << "📊 =========================================================\n\n";

    QmaskYieldEngine yieldEngine;
    std::string userAccount = "qmpHolderWalletAddress_YoshikiStakerKing1";

    // CASE A: User locks 1,000 QMK base tokens for a long-term 5,000-block staging node runtime
    StakingPosition mockPosition = { 1000.00, 5000, 1200 };
    double blockFeesCollected = 45.50; // Active block fees flowing through the 60/40 engine [INDEX]
    yieldEngine.CalculateStakingYield(userAccount, mockPosition, blockFeesCollected);

    // CASE B: Gamer checks their rare Proof-of-Work beast into the training facility for 12 hours
    yieldEngine.ProcessAdventureStakingTick("NHYTRW", 12);

    return 0;
}
