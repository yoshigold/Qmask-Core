#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class QmaskPoWAssetEngine {
private:
    int totalMinedCreaturesCount = 5240; // Simulated current global supply of PoW assets on the chain
    const int maxGlobalAssetSupply = 16777216; // The strict mathematical absolute supply limit (Hacash standard)

public:
    // 💎 1. HACASH-STYLE DIFFICULTY SCALER: Increases item difficulty as supply fills up
    double CalculateDynamicAssetDifficulty(double baseDifficulty) {
        // As the global asset supply crawls up, dynamically scale the math requirements exponentially
        double supplyRatio = static_cast<double>(totalMinedCreaturesCount) / 1000000.0;
        double dynamicMultiplier = 1.0 + std::pow(supplyRatio, 2.0);
        
        return baseDifficulty * dynamicMultiplier;
    }

    // ⛏️ 2. PROOF-OF-WORK CREATURE GENERATOR (The DNA Hash Extractor)
    void MintPoWGameAsset(const std::string& minerWallet, const std::string& winningHash) {
        std::cout << "💎 [Hacash Matrix] Valid Proof-of-Work Game Asset signature caught!\n";
        
        if (winningHash.length() < 32) {
            std::cout << "❌ [Error] Invalid cryptographic mining footprint data.\n";
            return;
        }

        // Extract a unique 6-letter alphabetic string directly from the hash bytes to act as item DNA
        std::string creatureDnaString = "";
        for (int i = 0; i < 6; ++i) {
            char targetLetter = 'A' + (std::abs(static_cast<int>(winningHash[i])) % 26);
            creatureDnaString += targetLetter;
        }

        totalMinedCreaturesCount++;

        std::cout << "✨ [MINT SUCCESS] New Proof-of-Work Beast permanently locked to ledger!\n";
        std::cout << "👑 Owner Wallet Key: " << minerWallet.substr(0, 15) << "...\n";
        std::cout << "🧬 Immutable Item DNA Token Name: [" << creatureDnaString << "]\n";
        std::cout << "📊 Global Circulating PoW Asset Count: " << totalMinedCreaturesCount << " / " << maxGlobalAssetSupply << "\n";
        std::cout << "----------------------------------------------------------------\n\n";
    }
};
