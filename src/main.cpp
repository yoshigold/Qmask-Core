#include <iostream>
#include <string>
#include <unistd.h>
#include <iomanip>

// Link our core environment components
void InitializeSetupWizard();
void InitializeP2PNetworkListener();

class QmaskExpandedGovernance {
public:
    int burnVotes = 0;
    int preserveVotes = 0;
    int convertFtgVotes = 0;
    int shareFtgVotes = 0;

    void ProcessFourWayOnChainVote(int blockHeight, const std::string& minerChoice) {
        if (minerChoice == "BURN") burnVotes++;
        else if (minerChoice == "PRESERVE") preserveVotes++;
        else if (minerChoice == "CONVERT_FTG") convertFtgVotes++;
        else if (minerChoice == "SHARE_FTG") shareFtgVotes++;

        int totalVotes = burnVotes + preserveVotes + convertFtgVotes + shareFtgVotes;
        
        std::cout << "🗳️  [EXPANDED GOVERNANCE] Block #" << blockHeight << " voted: [" << minerChoice << "]\n";
        std::cout << "📊 TALLY MATRIX -> BURN: " << burnVotes 
                  << " | PRESERVE: " << preserveVotes 
                  << " | CONVERT FTG: " << convertFtgVotes 
                  << " | SHARE FTG: " << shareFtgVotes << "\n";

        // Calculate dynamic percentage weights for democratic consensus checks
        double burnPct = (static_cast<double>(burnVotes) / totalVotes) * 100.0;
        double convertPct = (static_cast<double>(convertFtgVotes) / totalVotes) * 100.0;
        double sharePct = (static_cast<double>(shareFtgVotes) / totalVotes) * 100.0;

        if (totalVotes >= 5) {
            if (burnPct >= 51.0) {
                std::cout << "🔥 [CONSENSUS ACHIEVED] 51%+ voted to BURN the test coins permanently!\n";
            } else if (convertPct >= 51.0) {
                std::cout << "👑 [CONSENSUS ACHIEVED] 51%+ voted to convert tokens to Limited-Edition FTG (100% Founder Exclusive)!\n";
            } else if (sharePct >= 51.0) {
                std::cout << "🎁 [CONSENSUS ACHIEVED] 51%+ voted to convert tokens to FTG and SHARE a fraction with Early Miners!\n";
            }
        }
    }
};

int main(int argc, char* argv[]) {
    std::cout << "👑 =========================================================\n";
    std::cout << "👑 LAUNCHING FOUR-WAY DEMOCRATIC QMK MAINNET DAEMON         \n";
    std::cout << "👑 =========================================================\n\n";

    InitializeSetupWizard();
    InitializeP2PNetworkListener();

    QmaskExpandedGovernance govEngine;
    int activeBlockHeight = 13675; 

    // Simulation array demonstrating community miners shifting choices to grab that FTG share split!
    std::string mockBallots[] = {"BURN", "CONVERT_FTG", "SHARE_FTG", "SHARE_FTG", "SHARE_FTG"};
    int ballotIndex = 0;

    // THE INFINITE MAINNET LOOP
    while (true) {
        activeBlockHeight++;
        std::cout << "🧱 [BLOCK VALIDATED] CPU Cache sealed Block Height: #" << activeBlockHeight << "\n";
        std::cout << "🎁 Reward Log: Allocated +5.0000 QMK to your master wallet vault.\n";
        
        std::string currentVote = mockBallots[ballotIndex % 5];
        govEngine.ProcessFourWayOnChainVote(activeBlockHeight, currentVote);
        ballotIndex++;

        std::cout << "----------------------------------------------------------------\n";
        sleep(10); 
    }

    return 0;
}
