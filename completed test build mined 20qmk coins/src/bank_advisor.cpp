#include <iostream>
#include <string>
#include <iomanip>

class QmaskBankAdvisor {
public:
    // 📯 FUNCTION: Evaluates node maturity states and displays non-intrusive advisor choices
    void AuditStakingMaturityAndAdvise(const std::string& userAddress, int blocksStaked, double currentQgfMarketDemandFactor) {
        const int maturityLimitBlocks = 20000;
        
        std::cout << "🏦 =========================================================\n";
        std::cout << "🏦 QMASK SOVEREIGN BANK ADVISOR TERMINAL LAYER INTERFACE     \n";
        std::cout << "🏦 =========================================================\n";
        std::cout << "👤 Target Account Holder: " << userAddress.substr(0, 18) << "...\n";
        std::cout << "⏱️  Staking Lifetime Clock: " << blocksStaked << " / " << maturityLimitBlocks << " Blocks\n";

        if (blocksStaked < maturityLimitBlocks) {
            std::cout << "🟢 Advisor Status: Position is growing cleanly. Premium 5x multipliers are locked in.\n";
            std::cout << "----------------------------------------------------------------\n\n";
            return;
        }

        // Maturity Cliff hit: Print out our custom bank advisory indicator screen
        std::cout << "⚠️  [ADVISORY NOTICE] Your Sovereign Staking position has achieved full maturity.\n";
        std::cout << "📉 Multiplier Event: Premium booster has naturally decayed to standard 1x baseline.\n\n";
        std::cout << "💡 PROTOCOL ADVISORY INSIGHTS — CHOOSE YOUR PREFERRED FREEDOM DIRECTION:\n";
        std::cout << "   [PATH 1]: Continue holding long-term. Your coins remain 100% safe at 1x baseline yield.\n";
        
        // Dynamic advice calculation inspired by PBC's treasury indicators
        if (currentQgfMarketDemandFactor > 1.5) {
            std::cout << "   [PATH 2 (🔥 RECOMMENDED)]: High QGF Gas Fuel utility demand detected (Factor: " 
                      << currentQgfMarketDemandFactor << "x)!\n";
            std::cout << "             Converting your mature rewards into QGF right now presents an optimal\n";
            std::cout << "             arbitrage window to capture massive instant gameplay trading returns.\n";
        } else {
            std::cout << "   [PATH 2]: Convert rewards to liquid QGF trading capital to prepare for Season 3 gameplay.\n";
        }
        std::cout << "----------------------------------------------------------------\n\n";
    }
};

int main() {
    QmaskBankAdvisor advisorEngine;
    std::string testUser = "qmpPUB_YoshikiSovereignBankWhaleAccount999";

    // Scenario A: User's position is fresh and mining efficiently
    advisorEngine.AuditStakingMaturityAndAdvise(testUser, 4500, 1.1);

    // Scenario B: User's position has matured, and the engine detects high game-loop utility volume
    advisorEngine.AuditStakingMaturityAndAdvise(testUser, 22500, 1.85);

    return 0;
}
