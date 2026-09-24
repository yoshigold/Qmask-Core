#include <iostream>
#include <string>
#include <vector>
#include <map>

// Dynamic configuration structure expected by block.cpp
class NetParams {
public:
    static const size_t MAX_BLOCK_SIZE = 2000000; // 2MB Max block size rule
};
const size_t NetParams::MAX_BLOCK_SIZE;

namespace MONEU {

struct GenesisAllocation {
    std::string walletAddress;
    double initialSupplyQMC;
};

class ProductionMainnetParams {
public:
    std::string networkID;
    int publicP2PPort;
    int privateEncryptedPort;
    std::string defaultProductionTicker;
    
    std::vector<std::string> tickerReferendumBallot;
    std::map<std::string, double> genesisPremineDistributionBook;

    ProductionMainnetParams() {
        networkID = "QMASK_PRODUCTION_MAINNET";
        
        // 🌐 DUAL-PORT TRAFFIC CONTROL CONFIGURATION
        publicP2PPort = 8328;       // Public ledger transaction tracking
        privateEncryptedPort = 8329; // Advanced ZK-Folding privacy communications
        
        // Ticker Referendum default fallback winner
        defaultProductionTicker = "QMC"; 
        
        // Decentralised Referendum Ticker Ballot Options
        tickerReferendumBallot.push_back("QMC (Quantum Mask Coin / Classic Core Base)");
        tickerReferendumBallot.push_back("QMS (Quantum Mask Shadow Privacy Protocol)");
        tickerReferendumBallot.push_back("QMT (Quantum Mask Terminal Utility Layer)");
        tickerReferendumBallot.push_back("QMX (Quantum Mask Matrix Mutating Pipeline)");

        // 👑 GENESIS BLOCK #0 ALLOCATION BOOK (COMPRESSED TESTING LEDGER)
        // Hardcoding your hard-earned balances securely into the Genesis block parameters
        genesisPremineDistributionBook["qmk1q595wx...55aa"] = 9865.00000000; // Founder Master Keys Pool
        genesisPremineDistributionBook["qmk1q7p9vx...83a2"] = 1858.00000000; // Swarm Miner Partner 01
        genesisPremineDistributionBook["qmk1qx5z4l...29f1"] = 2180.00000000; // Swarm Miner Partner 02
        genesisPremineDistributionBook["qmk1q2w8sm...44e7"] = 3369.00000000; // Swarm Miner Partner 03
        genesisPremineDistributionBook["qmk1q99xxz...77aa"] = 14.11000000;  // Intel-i7-Secondary Node
    }

    void PrintGenesisResetConfiguration() const {
        std::cout << "=========================================================\n";
        std::cout << "       QMASK PRODUCTION GENESIS RESET CODE PARAMETERS    \n";
        std::cout << "=========================================================\n";
        std::cout << " Target Network Status: " << networkID << "\n";
        std::cout << " Primary P2P Base Port: " << publicP2PPort << " [Public Ledger Channel]\n";
        std::cout << " Secondary Mesh Port  : " << privateEncryptedPort << " [Private Shielded Channel]\n";
        std::cout << " Initial Block Height : #0 (Clean Genesis Blank Canvas)\n";
        std::cout << " Maximum Block Limit  : " << NetParams::MAX_BLOCK_SIZE << " Bytes (2MB Cap)\n";
        std::cout << "---------------------------------------------------------\n";
        std::cout << " 👑 PRODUCTION GENESIS BLOCK #0 DISTRIBUTION BALANCE SHEET:\n";
        
        double totalGenesisSupply = 0.0;
        for (const auto& pair : genesisPremineDistributionBook) {
            std::cout << "  -> Address: " << pair.first << " | Allocated: " 
                      << std::fixed << pair.second << " " << defaultProductionTicker << "\n";
            totalGenesisSupply += pair.second;
        }
        
        std::cout << " -> Total Compact Production Supply: " << totalGenesisSupply << " QMC\n";
        std::cout << "=========================================================\n";
    }
};

void TriggerGenesisResetEvaluation() {
    ProductionMainnetParams params;
    params.PrintGenesisResetConfiguration();
}

} // namespace MONEU
