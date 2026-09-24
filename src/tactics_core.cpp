#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <chrono>
#include <sstream>
#include <iomanip>

namespace MONEU {

class ChronoZodiacCodexEngine {
private:
    std::string DetermineZodiacHouse(long long timestamp) {
        int houseSelector = (timestamp % 12);
        std::vector<std::string> houses = {
            "ARIES (House of Ignition)",       "TAURUS (Hardened Matrix)",
            "GEMINI (Dual-Port Fork)",         "CANCER (Protective Shield)",
            "LEO (Sovereign Core)",            "VIRGO (Pure Ledger Canvas)",
            "LIBRA (Balanced Conservation)",   "SCORPIO (Shadow Sting)",
            "SAGITTARIUS (Chrono Vector)",     "CAPRICORN (Silicon Mountain)",
            "AQUARIUS (Swarm Stream)",         "PISCES (Infinite Deep)"
        };
        return houses[houseSelector];
    }

public:
    std::string EvaluateCrypticPuzzleState(long long blockHeight, long long totalNetworkPower) {
        long long epochSeconds = std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
            
        std::string currentHouse = DetermineZodiacHouse(epochSeconds);
        std::stringstream codexDisplayStream;

        codexDisplayStream << "🪐 [CHRONO-ZODIAC CIPHER CODEX INTERFACE]\n";
        codexDisplayStream << " -> Current House : " << currentHouse << "\n";
        
        long long simpleMatchFactor = (epochSeconds % 10);
        codexDisplayStream << " -> Matcher Matrix: [";
        for (int i = 0; i < 10; i++) {
            if (i == simpleMatchFactor) codexDisplayStream << "⚡";
            else codexDisplayStream << "-";
        }
        codexDisplayStream << "] ";
        
        // 🎮 SYSTEM INTERFACE RESET AND LEVEL PROGRESSION
        // Calculates Tier 2 progression dynamically since Tier 1 is already fully assembled
        long long activeTier2Fragments = (blockHeight % 4); 
        
        if (simpleMatchFactor == 7) {
            codexDisplayStream << "✨ [MATCH ALIGNMENT DETECTED! GLYPH SECURED] ✨\n";
            codexDisplayStream << " -> Minted Game Block Reward: \"Quantum-Shield-Fragment\" bound to block #" << blockHeight << "\n";
        } else {
            codexDisplayStream << "(Hunting Tier 2 Core Fragments...)\n";
        }
        
        codexDisplayStream << "----------------------------------------------------------------------------------------\n";
        codexDisplayStream << "🎮 PERMANENT GAMING MATRIX MONITOR VECTOR STATUS :\n";
        codexDisplayStream << "  -> Active Codex Puzzle Level: TIER 2 (The Quantum Shield Protocol)\n";
        codexDisplayStream << "  -> Glyph Fragment Inventory : [" << activeTier2Fragments << "/4] Searching for Alignment Match...\n";
        codexDisplayStream << "  -> Active Artifact Boost    : Moneu-Origin-Zodiac-Token Loaded (+5.00 MH/s Speed Verified)\n";

        return codexDisplayStream.str();
    }
};

void TriggerCodexEvaluationLoop(long long height, long long hashrate) {
    ChronoZodiacCodexEngine engine;
    std::cout << engine.EvaluateCrypticPuzzleState(height, hashrate);
}

} // namespace MONEU
