#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <fstream>

namespace MONEU {

struct PlayerPositionState {
    int xCoord;
    int yCoord;
    std::string activeMonsterName;
    int monsterLevel;
    int accumulatedGlyphs;
};

class QmaskTacticMonsterEngine {
private:
    int gridWidth = 16;
    int gridHeight = 6;
    const std::string STATE_FILE = "game_state.dat";

    // 💾 READ STATE FROM DISK
    PlayerPositionState LoadStateFromDisk() {
        PlayerPositionState state = {4, 2, "Xenomorph_V1", 12, 4}; // Baseline default
        std::ifstream fileIn(STATE_FILE);
        if (fileIn.is_open()) {
            fileIn >> state.xCoord >> state.yCoord >> state.monsterLevel >> state.accumulatedGlyphs;
            fileIn.close();
        }
        return state;
    }

    // 💾 SAVE STATE TO DISK
    void SaveStateToDisk(const PlayerPositionState& state) {
        std::ofstream fileOut(STATE_FILE);
        if (fileOut.is_open()) {
            fileOut << state.xCoord << " " << state.yCoord << " " << state.monsterLevel << " " << state.accumulatedGlyphs;
            fileOut.close();
        }
    }

public:
    void ProcessPlayerInputMovement(char actionKey) {
        PlayerPositionState player = LoadStateFromDisk();

        if ((actionKey == 'w' || actionKey == 'W') && player.yCoord > 0) player.yCoord--;
        if ((actionKey == 's' || actionKey == 'S') && player.yCoord < gridHeight - 1) player.yCoord++;
        if ((actionKey == 'a' || actionKey == 'A') && player.xCoord > 0) player.xCoord--;
        if ((actionKey == 'd' || actionKey == 'D') && player.xCoord < gridWidth - 1) player.xCoord++;
        
        if (rand() % 15 == 7) {
            player.monsterLevel++;
        }

        SaveStateToDisk(player);
    }

    void RenderInteractiveGameViewport() {
        PlayerPositionState player = LoadStateFromDisk();

        std::cout << "========================================================================================\n";
        std::cout << "   🎭 QMASK TACTICAL MONSTER ADVENTURE ENGINE (QMTM SEPARATE GAME NETWORK) 🎭          \n";
        std::cout << "========================================================================================\n";
        std::cout << " Use [W A S D] Keys to Navigate the Sector Grid | Current Asset Chain: QMTM Native Token\n";
        std::cout << "----------------------------------------------------------------------------------------\n";

        for (int y = 0; y < gridHeight; y++) {
            std::cout << "   | ";
            for (int x = 0; x < gridWidth; x++) {
                if (x == player.xCoord && y == player.yCoord) {
                    std::cout << "👾 "; 
                } else if ((x == 12 && y == 4) || (x == 2 && y == 1)) {
                    std::cout << "💎 "; 
                } else {
                    std::cout << ".  ";
                }
            }
            std::cout << "|\n";
        }

        std::cout << "----------------------------------------------------------------------------------------\n";
        std::cout << " 📋 ACTIVE COMPRESSED MONSTER TELEMETRY STATS TAB:\n";
        std::cout << "   -> Loaded Companion : " << player.activeMonsterName << " [Rarity Class: CHRONO_MYST]\n";
        std::cout << "   -> Combat Level     : Lvl " << player.monsterLevel << " [Virtual Hash Multiplier: " << std::fixed << std::setprecision(2) << 1.0 + (player.monsterLevel * 0.05) << "x]\n";
        std::cout << "   -> Coordinates      : Sector (X: " << player.xCoord << ", Y: " << player.yCoord << ")\n";
        std::cout << "   -> Locked Vault Key : qmtm_wallet_active_secure_mesh_handshake_port_8340\n";
        std::cout << "========================================================================================\n";
    }
};

static QmaskTacticMonsterEngine globalGameEngineInstance;

void RunGameConsoleEngineFrame(char inputCommand) {
    globalGameEngineInstance.ProcessPlayerInputMovement(inputCommand);
    globalGameEngineInstance.RenderInteractiveGameViewport();
}

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
        
        long long activeTier2Fragments = (blockHeight % 4); 
        
        if (simpleMatchFactor == 7) {
            codexDisplayStream << "✨ [MATCH ALIGNMENT DETECTED! GLYPH SECURED] ✨\n";
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
