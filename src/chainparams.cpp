#include <iostream>
#include <string>
#include <vector>

namespace MONEU {

class ProductionMainnetParams {
public:
    std::string networkID;
    int publicP2PPort;
    int privateEncryptedPort;
    std::string defaultProductionTicker;
    
    std::vector<std::string> tickerReferendumBallot;

    ProductionMainnetParams() {
        networkID = "QMASK_PRODUCTION_MAINNET";
        
        // Dual-Port Traffic Control Allocation Slices
        publicP2PPort = 8328;       
        privateEncryptedPort = 8329; 
        
        // 🌟 LOCKED IN FOUNDER PREFERENCE: Default set straight to QMC
        defaultProductionTicker = "QMC"; 
        
        // 🗳️ UPDATED DECENTRALIZED REFERENDUM TICKER BALLOT
        tickerReferendumBallot.push_back("QMC (Quantum Mask Coin / Classic Core Base)");
        tickerReferendumBallot.push_back("QMS (Quantum Mask Shadow Privacy Protocol)");
        tickerReferendumBallot.push_back("QMT (Quantum Mask Terminal Utility Layer)");
        tickerReferendumBallot.push_back("QMX (Quantum Mask Matrix Mutating Pipeline)");
    }

    void PrintGenesisResetConfiguration() const {
        std::cout << "=========================================================\n";
        std::cout << "       QMASK PRODUCTION GENESIS RESET CODE PARAMETERS    \n";
        std::cout << "=========================================================\n";
        std::cout << " Target Network Status: " << networkID << "\n";
        std::cout << " Primary P2P Base Port: " << publicP2PPort << " [Public Ledger Channel]\n";
        std::cout << " Secondary Mesh Port  : " << privateEncryptedPort << " [Private Shielded Channel]\n";
        std::cout << " Initial Block Height : #0 (Clean Genesis Blank Canvas)\n";
        std::cout << "---------------------------------------------------------\n";
        std::cout << " 🗳️ ACTIVE MAINNET GOVERNANCE TICKER REFERENDUM OPTIONS:\n";
        for (size_t i = 0; i < tickerReferendumBallot.size(); i++) {
            std::cout << "  -> Option [" << i + 1 << "]: " << tickerReferendumBallot[i] << "\n";
        }
        std::cout << "---------------------------------------------------------\n";
        std::cout << " SHARE_FTG Consensus Evaluation Window Active toward Block #347161\n";
        std::cout << "=========================================================\n";
    }
};

void TriggerGenesisResetEvaluation() {
    ProductionMainnetParams params;
    params.PrintGenesisResetConfiguration();
}

} // namespace MONEU
