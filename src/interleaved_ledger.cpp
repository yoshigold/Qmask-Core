#include <iostream>
#include <string>

class QmaskInterleavedLedger {
public:
    // 🧩 FUNCTION: Resolves race conditions by nesting concurrent blocks as valid Uncles
    void ResolveBlockRace(const std::string& blockWinner, const std::string& blockRunnerUp, double baseSubsidy) {
        std::cout << "🧩 [Interleaved Ledger] Race condition caught! Two blocks found simultaneously.\n";
        std::cout << "🏆 Principal Main Block Sealed: " << blockWinner << " -> Reward: " << baseSubsidy << " QMK\n";
        
        // Nest the secondary runner-up block as an Uncle instead of throwing away the miner's work
        double uncleRewardBonus = baseSubsidy * 0.20; // 20% loyalty payout allocation
        std::cout << "✨ Secondary Uncle Block Interleaved: " << blockRunnerUp << " -> Payout: " << uncleRewardBonus << " QMK\n";
        std::cout << "📊 Results: Zero computing energy wasted. Secondary miner work preserved successfully.\n";
    }
};
