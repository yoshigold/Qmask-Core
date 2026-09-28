#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class QmaskGameGenerationEngine {
public:
    // 🎭 FUNCTION: Decodes a raw transaction hash to extract procedural game world assets
    void DecodeHashToGameAssets(int blockHeight, const std::string& transactionHash) {
        if (transactionHash.length() < 32) {
            std::cout << "❌ [Error] Invalid transaction hash data footprint format.\n";
            return;
        }

        std::cout << "⛏️  [Game Engine] Reading Block #" << blockHeight << " Data Matrices...\n";
        std::cout << "📋 Source Tx Hash Input: " << transactionHash << "\n";

        // 1. GENERATE UNIQUE USERNAME FROM HASH BYTES
        // Take 4 distinctive chunks of the hash to construct a pseudo-random character pattern
        char syllable1 = 'A' + (transactionHash[2] % 26);
        char syllable2 = 'a' + (transactionHash[5] % 26);
        char syllable3 = 'k' + (transactionHash[9] % 26);
        char syllable4 = 'o' + (transactionHash[14] % 26);
        
        std::string generatedName = "";
        generatedName += syllable1;
        generatedName += syllable2;
        generatedName += syllable3;
        generatedName += syllable4;
        
        // 2. GENERATE MAP TILES SEED
        int environmentalTileSeed = static_cast<int>(transactionHash[20]) * 7;

        // 3. GENERATE WILD CREATURE SPAWN ENCOUNTER RATES (Pokémon style check)
        int shinyMonsterEncounterChance = (static_cast<int>(transactionHash[30]) + blockHeight) % 100;

        // Print the procedural outcomes live
        std::cout << "🎭 Generated Unique Player Username: " << generatedName << "_Trainer\n";
        std::cout << "🧱 Isometric Tile Generation Seed   : " << environmentalTileSeed << " (Map Grid Render Lock)\n";
        std::cout << "👾 Wild Creature Rarity Catch Rate  : " << shinyMonsterEncounterChance << "% Encounter Probability\n";
        
        // 🏁 REVEAL HISTORICAL SECRET STORY CHAPTERS AT MILESTONE BLOCK TARGETS
        if (blockHeight >= 13675) {
            std::cout << "🔓 [MILESTONE REVEAL] Secrets of the Peer-to-Peer Electronic Cash System Unlocked:\n";
            std::cout << "   \"Satoshi Nakamoto: If you don't believe me or don't get it, I don't have time to try to convince you, sorry.\"\n";
        }
        std::cout << "----------------------------------------------------------------\n\n";
    }
};
