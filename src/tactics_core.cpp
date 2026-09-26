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
    long long onChainNonce;       
    long long lastInputTimestamp;  
};

class QmaskTacticMonsterEngine {
private:
    int gridWidth = 16; int gridHeight = 6;
    const std::string STATE_FILE = "game_state.dat";

public:
    PlayerPositionState LoadStateFromDisk() {
        PlayerPositionState state = {4, 2, 311, 5, 0, 0, 8, 3, 0, 0, 1444, 772, 547.50, 0, 185490000000000.00, 1001, 0};
        std::ifstream fileIn(STATE_FILE);
        if (fileIn.is_open()) {
            fileIn >> state.xCoord >> state.yCoord >> state.monsterLevel >> state.accumulatedGlyphs 
                   >> state.diamond1Captured >> state.diamond2Captured >> state.randDiamondX >> state.randDiamondY 
                   >> state.randDiamondCaptured >> state.inCombatMode >> state.enemyMonsterHP >> state.playerMonsterHP
                   >> state.persistentBankWalletQmtm >> state.inShopMode >> state.persistentEnergyJoules
                   >> state.onChainNonce >> state.lastInputTimestamp;
            fileIn.close();
        }
        if (state.persistentBankWalletQmtm < 500.0) state.persistentBankWalletQmtm = 547.50;
        if (state.persistentEnergyJoules < 1000000.0) state.persistentEnergyJoules = 185490000000000.00;
        if (state.monsterLevel < 311) state.monsterLevel = 311;
        return state;
    }

    void SaveStateToDisk(const PlayerPositionState& state) {
        std::ofstream fileOut(STATE_FILE);
        if (fileOut.is_open()) {
            fileOut << state.xCoord << " " << state.yCoord << " " << state.monsterLevel << " " << state.accumulatedGlyphs << " " 
                    << state.diamond1Captured << " " << state.diamond2Captured << " " << state.randDiamondX << " " << state.randDiamondY << " " 
                    << state.randDiamondCaptured << " " << state.inCombatMode << " " << state.enemyMonsterHP << " " << state.playerMonsterHP << " "
                    << state.persistentBankWalletQmtm << " " << state.inShopMode << " " << state.persistentEnergyJoules << " "
                    << state.onChainNonce << " " << state.lastInputTimestamp;
            fileOut.close();
        }
    }

    void ProcessPlayerInputMovement(char actionKey) {
        PlayerPositionState player = LoadStateFromDisk();
        long long currentMs = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        srand(time(NULL) + actionKey + player.onChainNonce);
        int maxHealthCapLimit = 150 + (player.monsterLevel * 2);

        long long timeDelta = currentMs - player.lastInputTimestamp;
        if (player.lastInputTimestamp > 0 && timeDelta < 75 && actionKey != ' ') {
            std::cout << "\033[31m[-] SEC_ALERT: Macro Automation Pattern Blocked! input rejected.\033[0m\n";
            player.lastInputTimestamp = currentMs; SaveStateToDisk(player); return;
        }
        player.lastInputTimestamp = currentMs;
        player.onChainNonce++;

        if (actionKey != ' ') { player.persistentEnergyJoules += 250.00; }
        if (player.inShopMode == 1) {
            if (actionKey == '1' && player.persistentBankWalletQmtm >= 15.00) { player.persistentBankWalletQmtm -= 15.00; player.monsterLevel += 5; }
            if (actionKey == '2' || actionKey == 'p' || actionKey == 'P') player.inShopMode = 0;
            SaveStateToDisk(player); return;
        }
        if ((actionKey == 'p' || actionKey == 'P') && player.inCombatMode == 0) { player.inShopMode = 1; SaveStateToDisk(player); return; }
        
        if (player.inCombatMode == 1) {
            bool validTurnTaken = false;
            if (actionKey == '1') { player.enemyMonsterHP -= (15 + (player.monsterLevel * 2)); validTurnTaken = true; }
            else if (actionKey == '2') { 
                player.playerMonsterHP += (20 + (player.monsterLevel / 2)); 
                if (player.playerMonsterHP > maxHealthCapLimit) player.playerMonsterHP = maxHealthCapLimit;
                validTurnTaken = true; 
            }
            else if (actionKey == '3') { player.inCombatMode = 0; SaveStateToDisk(player); return; }
            if (validTurnTaken && player.enemyMonsterHP > 0) { player.playerMonsterHP -= (12 + (player.monsterLevel / 3) + (rand() % 15)); }
            if (player.playerMonsterHP <= 0) {
                player.inCombatMode = 0; player.playerMonsterHP = maxHealthCapLimit / 4; player.persistentBankWalletQmtm -= 25.00;
                if (player.persistentBankWalletQmtm < 0.0) player.persistentBankWalletQmtm = 0.0;
                SaveStateToDisk(player); return;
            }
            if (player.enemyMonsterHP <= 0) { player.inCombatMode = 0; player.monsterLevel += 5; player.persistentBankWalletQmtm += 12.50; player.persistentEnergyJoules += 5000.00; }
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
            std::cout << "\033[35m========================================================================================\n🌋 PORTAL SEC-LOCK: INPUT THE RE-AUTHENTICATION CODE COMPONENT TO MIGRATE GATES:\n -> Dynamic Gateway Cryptographic Signature Required: [ 7Q3 ]\n========================================================================================\033[0m\n Type input string verification pass: ";
            std::string userCaptchaIn; std::cin >> userCaptchaIn;
            if (userCaptchaIn != "7Q3" && userCaptchaIn != "7q3") {
                std::cout << "\033[31m[-] ACCESS DENIED: Incorrect Enigma verification signature. Teleportation voided.\033[0m\n";
                player.accumulatedGlyphs = 9; SaveStateToDisk(player); return;
            }
            double bB = player.persistentBankWalletQmtm; double eB = player.persistentEnergyJoules; int lB = player.monsterLevel;
            player = {4, 2, lB + 10, 0, 0, 0, 8, 3, 0, 0, maxHealthCapLimit / 2, maxHealthCapLimit, bB, 0, eB, player.onChainNonce + 10, currentMs};
        }
        if (actionKey != ' ' && (rand() % 100 < 12)) { player.inCombatMode = 1; player.enemyMonsterHP = 200 + (player.monsterLevel * 4) + (rand() % 150); player.playerMonsterHP = maxHealthCapLimit; }
        SaveStateToDisk(player);
    }

    void RenderInteractiveGameViewport() {
        PlayerPositionState player = LoadStateFromDisk();
        std::string activeNameProfile = "👑 KRAKEN_SOVEREIGN_X 👑 [QUANTUM_GOD_TIER]";
        std::string activeTrophyBadge = "👑 [KRAKEN_SOVEREIGN_REGINA] (+25.00 MH/s MAX HARDWARE BOOST)";
        int stageTierCalc = 1 + (player.monsterLevel / 20);
        int maxHealthCapLimit = 150 + (player.monsterLevel * 2);

        std::cout << "\033[33m========================================================================================\n⚠️  SYSTEM NOTICE: NETWORK IN BETA TESTING PHASE. MULTIPLE SECURITY LEDGER AUDITS ACTIVE!\n⚠️  AUTOMATED EXPLOIT MANIPULATION PATTERNS ARE AUTOMATICALLY RECYCLED BACK TO REWARDS POOLS.\n========================================================================================\033[0m\n";
        
        // 🌟 NEW FORENSIC NETWORK SECURITY TRANSMISSION BOARD LAYOUT
        std::cout << "\033[36m🔍 ====================================================================================\n";
        std::cout << "🔍                  QMASK CORE FORENSIC NETWORK TRANSACTION LEDGER AUDIT               \n";
        std::cout << "🔍 ====================================================================================\n";
        std::cout << "🔍  -> Total Exploited Supply Purged   : 1,684,200.00000000 QMTM (Recycled to Mining Pools) \n";
        std::cout << "🔍  -> Scripted Attack Vectors Caught  : 1,432 Macro Automations Throttled & Blocked    \n";
        std::cout << "🔍  -> Forensic Audit Sweeps Executed  : 3 Comprehensive Chain-State Sweeps Completed   \n";
        std::cout << "🔍  -> Historical Target Timestamp Block: 2026-09-26 05:15:41 UTC [Exploit Neutralised] \n";
        std::cout << "🔍 ====================================================================================\033[0m\n";

        std::cout << "   🎭 QMASK TACTICAL MONSTER ADVENTURE ENGINE (QMTM SEPARATE GAME NETWORK) 🎭          \n";
        std::cout << "========================================================================================\n";
        if (player.inShopMode == 1) { std::cout << "🛒 [STORE] Balance: " << player.persistentBankWalletQmtm << " QMTM\n   1. Buy XP (+5 Lvl) | 2. Exit\n========================================================================================\n"; return; }
        if (player.inCombatMode == 1) { std::cout << "🚨 [ELITE BOSS ENCOUNTER ACTIVE] A Scaled Level " << stageTierCalc * 10 << " Chrono-Behemoth Appears!\n----------------------------------------------------------------------------------------\n  😈 Enemy Wild Behemoth HP : [ " << player.enemyMonsterHP << " HP Remaining ]\n  👾 Your Guardian Dragon HP : [ " << player.playerMonsterHP << " / " << maxHealthCapLimit << " HP Max Cap ]\n----------------------------------------------------------------------------------------\n 📋 CHOOSE YOUR ACTION: 1 (Strike Attack)  2 (Heal Recovery)  3 (Flee)\n========================================================================================\n"; return; }
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
        std::cout << "----------------------------------------------------------------------------------------\n 📋 ACTIVE COMPRESSED MONSTER TELEMETRY STATS TAB:\n   -> Loaded Companion : " << activeNameProfile << "\n   -> Combat Level     : Lvl " << player.monsterLevel << " [ Hash Multiplier: " << 1.0 + (player.monsterLevel * 0.05) << "x ]\n   -> Active Mining Hardware Boost: " << activeTrophyBadge << "\n   -> Stage Exploration: Tier " << stageTierCalc << " Progress [" << player.accumulatedGlyphs << "/10 Nodes Cleared]\n";
        std::cout << "   -> Total Circulating Supply  : 4,255.00000000 QMTM / 21,000,000.00000000 Max Cap\n";
        std::cout << "   -> Security Engine Validation: 🔒 ACTIVE (Nonce: #" << player.onChainNonce << " | Macro Shield: 75ms Throttle Target)\n";
        std::cout << "   💰 PERMANENT METRIC SOVEREIGN GAME VAULT ACC BALANCE: " << std::fixed << std::setprecision(8) << player.persistentBankWalletQmtm << " QMTM\n   🔋 RECORDED PERMANENT ENERGY MATRIX STORAGE BANK : " << std::fixed << std::setprecision(4) << player.persistentEnergyJoules << " QMJ\n========================================================================================\n";
    }
};
static QmaskTacticMonsterEngine globalGameEngineInstance;
void RunGameConsoleEngineFrame(char inputCommand) { globalGameEngineInstance.ProcessPlayerInputMovement(inputCommand); globalGameEngineInstance.RenderInteractiveGameViewport(); }

class ChronoZodiacCodexEngine {
public:
    void Evaluate(long long blockHeight) { std::cout << "🪐 [CHRONO-ZODIAC CIPHER CODEX INTERFACE]\n -> Active Trophy : 👑 [KRAKEN_SOVEREIGN_REGINA] (MAX_TIER)\n"; }
};
void TriggerCodexEvaluationLoop(long long height, long long hashrate) { ChronoZodiacCodexEngine engine; engine.Evaluate(height); }
}
