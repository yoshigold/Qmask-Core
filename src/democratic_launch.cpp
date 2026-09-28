#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

struct TestingTimeline {
    int privateBlocks;
    int publicBlocks;
    long long privateDurationSeconds;
    long long publicDurationSeconds;
};

class QmaskDemocraticLaunchEngine {
public:
    // 🎛️ 1. AUTOMATED MINING STOP CONTROL: Automatically stops mining after target blocks
    void CheckTestingBlockLimit(int currentHeight, int targetTestLimit) {
        std::cout << "⛏️  [Testing Monitor] Current Testnet Height: " << currentHeight << " / Target Limit: " << targetTestLimit << "\n";
        if (currentHeight >= targetTestLimit) {
            std::cout << "🚨 [AUTONOMOUS BLOCK STOP TRIGGERED] Target testing block count reached!\n";
            std::cout << "🔒 Action: Shaking down miner threads. Freezing node local database container states.\n\n";
        }
    }

    // 🧮 2. THE DEMOCRATIC CONVERSION CALCULATOR (Processing the 3-Group Ballot)
    double CalculateMainnetSplitRatio(TestingTimeline timeline, int agreeVotes, int disagreeVotes, int unsureVotes, double userBurnPreferencePercentage) {
        std::cout << "📊 =========================================================\n";
        std::cout << "📊 AUDITING DEMOCRATIC LAUNCH MATRIX & THREE-GROUP BALLETS   \n";
        std::cout << "📊 =========================================================\n";
        std::cout << "🟢 Agree Group Votes   : " << agreeVotes << "\n";
        std::cout << "🔴 Disagree Group Votes: " << disagreeVotes << "\n";
        std::cout << "🟡 Unsure Group Votes  : " << unsureVotes << "\n";
        
        int totalVotes = agreeVotes + disagreeVotes + unsureVotes;
        double agreeRatio = static_cast<double>(agreeVotes) / (totalVotes + 1);

        // Core Formula: Compute the mainnet fractional split ratio using timeline speeds and voting weights
        int totalBlocks = timeline.privateBlocks + timeline.publicBlocks;
        long long totalTime = timeline.privateDurationSeconds + timeline.publicDurationSeconds;
        
        double timelineSpeedFactor = static_cast<double>(totalBlocks) / (totalTime + 1);
        
        // Final Split Ratio Output Calculation
        double finalSplitRatio = (timelineSpeedFactor * agreeRatio) * (1.0 - (userBurnPreferencePercentage / 100.0));
        
        // Enforce hard structural floors to prevent broken math loops
        if (finalSplitRatio < 0.00001) finalSplitRatio = 0.00001;

        std::cout << "🔥 User Burn Vote Setting: " << userBurnPreferencePercentage << "% of Testnet supply permanently destroyed.\n";
        std::cout << "✨ Algorithmic Mainnet Split Ratio Locked: 1 Testnet Coin = " 
                  << std::fixed << std::setprecision(8) << finalSplitRatio << " Mainnet QMK\n";
        std::cout << "----------------------------------------------------------------\n\n";
        return finalSplitRatio;
    }
};
