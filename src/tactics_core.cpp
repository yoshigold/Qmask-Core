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
    int xCoord; int yCoord; int monsterLevel; int accumulatedGlyphs;
    int diamond1Captured; int diamond2Captured; int randDiamondX; int randDiamondY;
    int randDiamondCaptured; int inCombatMode; int enemyMonsterHP; int playerMonsterHP;
    double persistentBankWalletQmtm; int inShopMode; double persistentEnergyJoules;
};

class QmaskTacticMonsterEngine {
private:
    int gridWidth = 16; int gridHeight = 6;
    const std::string STATE_FILE = "game_state.dat";

    PlayerPositionState LoadStateFromDisk() {
        // 💾 TRIPLE INTEGRITY DEFAULT INITIALIZER: Set to your exact peak progress baseline variables
        PlayerPositionState state = {4, 2, 35, 6, 0, 0, 8, 3, 0, 0, 100, 100, 385.50, 0, 185240.00};
        std::ifstream fileIn(STATE_FILE);
        if (fileIn.is_open()) {
            fileIn >> state.xCoord >> state.yCoord >> state.monsterLevel >> state.accumulatedGlyphs 
                   >> state.diamond1Captured >> state.diamond2Captured >> state.randDiamondX >> state.randDiamondY 
                   >> state.randDiamondCaptured >> state.inCombatMode >> state.enemyMonsterHP >> state.playerMonsterHP
                   >> state.persistentBankWalletQmtm >> state.inShopMode >> state.persistentEnergyJoules;
            fileIn.close();
        }
        return state;
    }

    void SaveStateToDisk(const PlayerPositionState& state) {
        std::ofstream fileOut(STATE_FILE);
        if (fileOut.is_open()) {
            fileOut << state.xCoord << " " << state.yCoord << " " << state.monsterLevel << " " << state.accumulatedGlyphs << " " 
                    << state.diamond1Captured << " " << state.diamond2Captured << " " << state.randDiamondX << " " << state.randDiamondY << " " 
                    << state.randDiamondCaptured << " " << state.inCombatMode << " " << state.enemyMonsterHP << " " << state.playerMonsterHP << " "
                    << state.persistentBankWalletQmtm << " " << state.inShopMode << " " << state.persistentEnergyJoules;
            fileOut.close();
        }
    }

public:
    void ProcessPlayerInputMovement(char actionKey) {
        PlayerPositionState player = LoadStateFromDisk();
        srand(time(NULL) + actionKey);
        if (actionKey != ' ') { player.persistentEnergyJoules += 250.00; }
        if (player.inShopMode == 1) {
            if (actionKey == '1' && player.persistentBankWalletQmtm >= 15.00) { player.persistentBankWalletQmtm -= 15.00; player.monsterLevel += 5; }
            if (actionKey == '2' || actionKey == 'p' || actionKey == 'P') { player.inShopMode = 0; }
            SaveStateToDisk(player); return;
        }
        if ((actionKey == 'p' || actionKey == 'P') && player.inCombatMode == 0) { player.inShopMode = 1; SaveStateToDisk(player); return; }
        if (player.inCombatMode == 1) {
            if (actionKey == '1') { player.enemyMonsterHP -= (15 + (player.monsterLevel * 2)); }
            else if (actionKey == '2') { player.playerMonsterHP += 10; }
            else if (actionKey == '3' || player.playerMonsterHP <= 0) { player.inCombatMode = 0; SaveStateToDisk(player); return; }
            if (player.enemyMonsterHP > 0) { player.playerMonsterHP -= (8 + (rand() % 10)); }
            else { player.inCombatMode = 0; player.monsterLevel += 2; player.persistentBankWalletQmtm += 2.50; player.persistentEnergyJoules += 1500.00; }
            SaveStateToDisk(player); return;
        }
        if (actionKey == 'w' || actionKey == 'W') { if (player.yCoord > 0) player.yCoord--; }
        if (actionKey == 's' || actionKey == 'S') { if (player.yCoord < gridHeight - 1) player.yCoord++; }
        if (actionKey == 'a' || actionKey == 'A') { if (player.xCoord > 0) player.xCoord--; }
        if (actionKey == 'd' || actionKey == 'D') { if (player.xCoord < gridWidth - 1) player.xCoord++; }
        if (player.xCoord == 12 && player.yCoord == 4 && player.diamond1Captured == 0) { player.diamond1Captured = 1; player.monsterLevel += 3; player.accumulatedGlyphs++; player.persistentBankWalletQmtm += 1.50; player.persistentEnergyJoules += 1000.00; }
        if (player.xCoord == 2 && player.yCoord == 1 && player.diamond2Captured == 0) { player.diamond2Captured = 1; player.monsterLevel += 3; player.accumulatedGlyphs++; player.persistentBankWalletQmtm += 1.50; player.persistentEnergyJoules += 1000.00; }
        if (player.diamond1Captured == 1 && player.diamond2Captured == 1 && player.xCoord == player.randDiamondX && player.yCoord == player.randDiamondY && player.randDiamondCaptured == 0) {
            player.randDiamondCaptured = 1; player.monsterLevel += 5; player.accumulatedGlyphs++; player.persistentBankWalletQmtm += 3.00; player.persistentEnergyJoules += 2000.00;
            player.randDiamondX = (rand() % (gridWidth - 2)) + 1; player.randDiamondY = (rand() % (gridHeight - 2)) + 1; player.randDiamondCaptured = 0;
        }
        if (player.accumulatedGlyphs >= 10 && player.xCoord == 8 && player.yCoord == 3) { 
            double bB = player.persistentBankWalletQmtm; double eB = player.persistentEnergyJoules; int lB = player.monsterLevel;
            player = {4, 2, lB + 10, 0, 0, 0, 8, 3, 0, 0, 100, 100, bB, 0, eB};
        }
        if (actionKey != ' ' && (rand() % 100 < 8)) { player.inCombatMode = 1; player.enemyMonsterHP = 40 + (rand() % 40); player.playerMonsterHP = 100; }
        SaveStateToDisk(player);
    }

    void RenderInteractiveGameViewport() {
        PlayerPositionState player = LoadStateFromDisk();
        std::string activeNameProfile = "Xenomorph_V1 [CHRONO_MYST]";
        std::string activeTrophyBadge = "🪐 [MONEU_ORIGIN_TOKEN] (+5.00 MH/s)";
        
        if (player.monsterLevel >= 20) { 
            activeNameProfile = "👑 KRAKEN_SOVEREIGN_X 👑 [QUANTUM_GOD_TIER]"; 
            activeTrophyBadge = "👑 [KRAKEN_SOVEREIGN_REGINA] (+25.00 MH/s MAX HARDWARE BOOST)";
        } else if (player.monsterLevel >= 12) {
            activeTrophyBadge = "⚡ [QUANTUM_SHIELD_KEY] (+12.50 MH/s TIER_2 BOOST)";
        }

        std::cout << "========================================================================================\n";
        std::cout << "   🎭 QMASK TACTICAL MONSTER ADVENTURE ENGINE (QMTM SEPARATE GAME NETWORK) 🎭          \n";
        std::cout << "========================================================================================\n";
        if (player.inShopMode == 1) { std::cout << "🛒 [QMASK PROTOCOL STORE FRONT] Balance: " << std::fixed << std::setprecision(2) << player.persistentBankWalletQmtm << " QMTM\n   1. Buy XP Injector (15.00 QMTM) | 2. Exit Store\n========================================================================================\n"; return; }
        if (player.inCombatMode == 1) { std::cout << "🚨 [WILD MONSTER ENCOUNTER ACTIVE] Viper HP: " << player.enemyMonsterHP << " | Your HP: " << player.playerMonsterHP << "\n   1 (Strike Attack)  2 (Shield Defend)  3 (Flee)\n========================================================================================\n"; return; }
        std::cout << " Move via [W A S D] | Press [P] to Open Store Front\n----------------------------------------------------------------------------------------\n";
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
        std::cout << "   -> Loaded Companion : " << activeNameProfile << "\n";
        std::cout << "   -> Combat Level     : Lvl " << player.monsterLevel << " [ Hash Multiplier: " << 1.0 + (player.monsterLevel * 0.05) << "x ]\n";
        std::cout << "   -> Active Mining Hardware Boost: " << activeTrophyBadge << "\n";
        std::cout << "   -> Stage Progress  : [" << player.accumulatedGlyphs << "/10 Nodes Cleared]\n";
        std::cout << "   💰 PERMANENT METRIC SOVEREIGN GAME VAULT ACC BALANCE: " << std::fixed << std::setprecision(8) << player.persistentBankWalletQmtm << " QMTM\n";
        std::cout << "   🔋 RECORDED PERMANENT ENERGY MATRIX STORAGE BANK : " << std::fixed << std::setprecision(4) << player.persistentEnergyJoules << " QMJ\n";
        std::cout << "========================================================================================\n";
    }
};
static QmaskTacticMonsterEngine globalGameEngineInstance;
void RunGameConsoleEngineFrame(char inputCommand) { globalGameEngineInstance.ProcessPlayerInputMovement(inputCommand); globalGameEngineInstance.RenderInteractiveGameViewport(); }

class ChronoZodiacCodexEngine {
private:
    std::string DetermineZodiacHouse(long long timestamp) {
        int houseSelector = (timestamp % 12);
        std::vector<std::string> houses = {
            "ARIES (House of Ignition)", "TAURUS (Hardened Matrix)", "GEMINI (Dual-Port Fork)", "CANCER (Protective Shield)",
            "LEO (Sovereign Core)", "VIRGO (Pure Ledger Canvas)", "LIBRA (Balanced Conservation)", "SCORPIO (Shadow Sting)",
            "SAGITTARIUS (Chrono Vector)", "CAPRICORN (Silicon Mountain)", "AQUARIUS (Swarm Stream)", "PISCES (Infinite Deep)"
        };
        return houses[houseSelector];
    }
public:
    std::string EvaluateCrypticPuzzleState(long long blockHeight, long long totalNetworkPower) {
        long long epochSeconds = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        std::string currentHouse = DetermineZodiacHouse(epochSeconds);
        std::stringstream codexDisplayStream;
        codexDisplayStream << "🪐 [CHRONO-ZODIAC CIPHER CODEX INTERFACE]\n -> Current House : " << currentHouse << "\n";
        
        // 🌟 DYNAMIC TROPHY READOUTS INJECTED INT THE CODEX INTERFACE TRACKS
        int monsterLvl = 35;
        std::ifstream f("game_state.dat");
        if (f.is_open()) {
            int dum; double dBl;
            f >> dum >> dum >> monsterLvl;
            f.close();
        }
        std::string tN = (monsterLvl >= 20) ? "👑 [KRAKEN_SOVEREIGN_REGINA] (MAX_TIER)" : "🪐 [MONEU_ORIGIN_TOKEN]";
        codexDisplayStream << " -> Active Trophy : " << tN << " (Booster Generating Shares)\n";

        long long activeTier2Fragments = (blockHeight % 4);
        if (activeTier2Fragments == 0 && blockHeight > 337823) {
            codexDisplayStream << " -> Matcher Matrix: [⚡⚡⚡--⚡⚡⚡--] ✨ TIER 3 ADVANCEMENT ARMED ✨\n";
        } else {
            codexDisplayStream << " -> Matcher Matrix: [";
            long long simpleMatchFactor = (epochSeconds % 10);
            for (int i = 0; i < 10; i++) { if (i == simpleMatchFactor) codexDisplayStream << "⚡"; else codexDisplayStream << "-"; }
            codexDisplayStream << "] (Hunting Tier 3 Fragments... [" << activeTier2Fragments << "/4])\n";
        }
        return codexDisplayStream.str();
    }
};
void TriggerCodexEvaluationLoop(long long height, long long hashrate) { ChronoZodiacCodexEngine engine; std::cout << engine.EvaluateCrypticPuzzleState(height, hashrate); }
} // namespace MONEU
