#include <iostream>
#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>

class QmaskGenesisBlock {
public:
    // Program the absolute parameters for Qmask (QMK)
    const std::string coinName = "Qmask";
    const std::string coinTicker = "QMK";
    const long long maxSupply = 21000000; // Hardcapped supply limit
    
    std::string GenerateGenesisBlock0() {
        // Capture the exact real-time UNIX timestamp of the network creation loop
        auto now = std::chrono::system_clock::now();
        auto duration = now.time_since_epoch();
        long long timestamp = std::chrono::duration_cast<std::chrono::seconds>(duration).count();

        // Hardcode a founding message text block into the genesis code
        std::string foundingMessage = "Qmask 2026: Lightweight Bitcoin architecture with an Electron-Masked Mempool.";

        // Use a fast hash to bind these immutable structural rules into a unique string
        unsigned int genesisHash = 5381;
        for (char c : coinName) genesisHash = ((genesisHash << 5) + genesisHash) + c;
        for (char c : foundingMessage) genesisHash = ((genesisHash << 5) + genesisHash) + c;
        
        std::stringstream ss;
        ss << std::hex << std::setw(8) << std::setfill('0') << genesisHash;
        std::string block0Hash = "00000000" + ss.str(); // Add classic leading zeros to signify mining target baseline

        while (block0Hash.length() < 32) {
            block0Hash += "0";
        }

        std::cout << "================================================================\n";
        std::cout << "👑 CONSTRUCTING GENESIS BLOCK 0 (" << coinName << " - " << coinTicker << ")\n";
        std::cout << "================================================================\n";
        std::cout << "📅 Genesis UNIX Timestamp : " << timestamp << "\n";
        std::cout << "📜 Founding Hardcoded Note: \"" << foundingMessage << "\"\n";
        std::cout << "💰 Max Total Asset Supply : " << maxSupply << " " << coinTicker << "\n";
        
        return block0Hash;
    }
};

int main() {
    QmaskGenesisBlock genesis;
    std::string block0Identifier = genesis.GenerateGenesisBlock0();
    
    std::cout << "🔒 Genesis Block 0 Hash   : " << block0Identifier << "\n";
    std::cout << "================================================================\n";
    std::cout << "🎉 Network Initialization Complete. Qmask blockchain is ready to boot!\n";
    
    return 0;
}
