#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

namespace MONEU {

struct PlayerPositionState {
    int xCoord;
    int yCoord;
    int monsterLevel;
    int accumulatedGlyphs;
    int diamond1Captured;
    int diamond2Captured;
    int randDiamondX;
    int randDiamondY;
    int randDiamondCaptured;
    int inCombatMode;     
    int enemyMonsterHP;   
    int playerMonsterHP;  
};

class QmaskTacticMonsterEngine {
private:
    int gridWidth = 16;
    int gridHeight = 6;
    const std::string STATE_FILE = "game_state.dat";

    PlayerPositionState LoadStateFromDisk() {
        PlayerPositionState state = {4, 2, 12, 4, 0, 0, 8, 3, 0, 0, 100, 100}; 
        std::ifstream fileIn(STATE_FILE);
        if (fileIn.is_open()) {
            fileIn >> state.xCoord >> state.yCoord >> state.monsterLevel >> state.accumulatedGlyphs 
                   >> state.diamond1Captured >> state.diamond2Captured 
                   >> state.randDiamondX >> state.randDiamondY >> state.randDiamondCaptured
                   >> state.inCombatMode >> state.enemyMonsterHP >> state.playerMonsterHP;
            fileIn.close();
        }
        return state;
    }

    void SaveStateToDisk(const PlayerPositionState& state) {
        std::ofstream fileOut(STATE_FILE);
        if (fileOut.is_open()) {
            fileOut << state.xCoord << " " << state.yCoord << " " << state.monsterLevel << " " << state.accumulatedGlyphs << " " 
                    << state.diamond1Captured << " " << state.diamond2Captured << " "
                    << state.randDiamondX << " " << state.randDiamondY << " " << state.randDiamondCaptured << " "
                    << state.inCombatMode << " " << state.enemyMonsterHP << " " << state.playerMonsterHP;
            fileOut.close();
        }
    }

public:
    void ProcessPlayerInputMovement(char actionKey) {
        PlayerPositionState player = LoadStateFromDisk();
        srand(time(NULL) + actionKey);

        if (player.inCombatMode == 1) {
            if (actionKey == '1') { player.enemyMonsterHP -= (15 + (player.monsterLevel * 2)); }
            else if (actionKey == '2') { player.playerMonsterHP += 10; }
            else if (actionKey == '3' || player.playerMonsterHP <= 0) { player.inCombatMode = 0; SaveStateToDisk(player); return; }

            if (player.enemyMonsterHP > 0) { player.playerMonsterHP -= (8 + (rand() % 10)); }
            else { player.inCombatMode = 0; player.monsterLevel += 2; player.accumulatedGlyphs += 2; }
            SaveStateToDisk(player); return;
        }

        // 🌟 HARDENED DIRECTION VECTORS: Fixed mapping paths explicitly to handle key signatures
        if (actionKey == 'w' || actionKey == 'W') { if (player.yCoord > 0) player.yCoord--; }
        if (actionKey == 's' || actionKey == 'S') { if (player.yCoord < gridHeight - 1) player.yCoord++; }
        if (actionKey == 'a' || actionKey == 'A') { if (player.xCoord > 0) player.xCoord--; }
        if (actionKey == 'd' || actionKey == 'D') { if (player.xCoord < gridWidth - 1) player.xCoord++; }
        
        if (player.xCoord == 12 && player.yCoord == 4 && player.diamond1Captured == 0) { player.diamond1Captured = 1; player.monsterLevel += 3; player.accumulatedGlyphs++; }
        if (player.xCoord == 2 && player.yCoord == 1 && player.diamond2Captured == 0) { player.diamond2Captured = 1; player.monsterLevel += 3; player.accumulatedGlyphs++; }

        if (player.diamond1Captured == 1 && player.diamond2Captured == 1) {
            if (player.xCoord == player.randDiamondX && player.yCoord == player.randDiamondY && player.randDiamondCaptured == 0) {
                player.randDiamondCaptured = 1; player.monsterLevel += 5; player.accumulatedGlyphs++;
                player.randDiamondX = (rand() % (gridWidth - 2)) + 1; player.randDiamondY = (rand() % (gridHeight - 2)) + 1; player.randDiamondCaptured = 0; 
            }
        }

        if (player.accumulatedGlyphs >= 10 && player.xCoord == 8 && player.yCoord == 3) { player.accumulatedGlyphs = 0; player.diamond1Captured = 0; player.diamond2Captured = 0; player.monsterLevel += 10; }
        if (actionKey != ' ' && (rand() % 100 < 8)) { player.inCombatMode = 1; player.enemyMonsterHP = 40 + (rand() % 40); player.playerMonsterHP = 100; }
        SaveStateToDisk(player);
    }

    void RenderInteractiveGameViewport() {
        PlayerPositionState player = LoadStateFromDisk();
        std::cout << "========================================================================================\n";
        std::cout << "   🎭 QMASK TACTICAL MONSTER ADVENTURE ENGINE (QMTM SEPARATE GAME NETWORK) 🎭          \n";
        std::cout << "========================================================================================\n";

        if (player.inCombatMode == 1) {
            std::cout << "🚨 [WILD MONSTER ENCOUNTER ACTIVE] A feral Lvl 15 Chrono-Viper blocks your path!\n";
            std::cout << "----------------------------------------------------------------------------------------\n";
            std::cout << "  😈 Enemy Wild Viper HP  : [ " << player.enemyMonsterHP << " HP Remaining ]\n";
            std::cout << "  👾 Your Xenomorph_V1 HP : [ " << player.playerMonsterHP << " / 100 HP Stable ]\n";
            std::cout << "----------------------------------------------------------------------------------------\n";
            std::cout << " 📋 CHOOSE YOUR ACTION: 1 (Strike Attack)  2 (Shield Defend)  3 (Flee Sector)\n";
            std::cout << "========================================================================================\n";
            return;
        }

        std::cout << " Use [W A S D] Keys to Navigate the Sector Grid | Current Asset Chain: QMTM Native Token\n";
        std::cout << "----------------------------------------------------------------------------------------\n";

        for (int y = 0; y < gridHeight; y++) {
            std::cout << "   | ";
            for (int x = 0; x < gridWidth; x++) {
                if (x == player.xCoord && y == player.yCoord) std::cout << "👾 "; 
                else if (player.accumulatedGlyphs >= 10 && x == 8 && y == 3) std::cout << "🌀 "; 
                else if (x == 12 && y == 4 && player.diamond1Captured == 0) std::cout << "💎 "; 
                else if (x == 2 && y == 1 && player.diamond2Captured == 0) std::cout << "💎 "; 
                else if (player.diamond1Captured == 1 && player.diamond2Captured == 1 && x == player.randDiamondX && y == player.randDiamondY && player.randDiamondCaptured == 0) std::cout << "🔥 "; 
                else std::cout << ".  ";
            }
            std::cout << "|\n";
        }

        std::cout << "----------------------------------------------------------------------------------------\n";
        std::cout << " 📋 ACTIVE COMPRESSED MONSTER TELEMETRY STATS TAB:\n";
        std::cout << "   -> Loaded Companion : Xenomorph_V1 [Rarity Class: CHRONO_MYST]\n";
        std::cout << "   -> Combat Level     : Lvl " << player.monsterLevel << " [ Hash Multiplier: " << 1.0 + (player.monsterLevel * 0.05) << "x ]\n";
        std::cout << "   -> Coordinates      : Sector (X: " << player.xCoord << ", Y: " << player.yCoord << ")\n";
        std::cout << "   -> Target Progress  : [" << player.accumulatedGlyphs << "/10] Crystals (Hit 10 to trigger Portal 🌀)\n";
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
        return codexDisplayStream.str();
    }
};

void TriggerCodexEvaluationLoop(long long height, long long hashrate) {
    ChronoZodiacCodexEngine engine;
    std::cout << engine.EvaluateCrypticPuzzleState(height, hashrate);
}

} // namespace MONEU
