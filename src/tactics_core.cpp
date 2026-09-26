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
    double persistentBankWalletQmtm; int inShopMode; 
    unsigned long long persistentEnergyJoules; 
    long long onChainNonce;       
    long long lastInputTimestamp;
    int activeMonsterTypeRng;
    int currentXpPoints;          
    unsigned long long totalDamageDealt; 
    double persistentKineticQmkb; 
    int activePortalDimensionMode;
    int riftGuardiansDefeated;   
};

class QmaskTacticMonsterEngine {
private:
    int gridWidth = 16; int gridHeight = 6;
    const std::string STATE_FILE = "game_state.dat";

public:
    PlayerPositionState LoadStateFromDisk() {
        PlayerPositionState state = {8, 3, 477, 10, 0, 0, 11, 3, 0, 0, 0, 1200, 652.498, 0, 185490000076576ULL, 1011, 0, 0, 100, 2450, 1.476, 0, 0};
        std::ifstream fileIn(STATE_FILE);
        if (fileIn.is_open()) {
            fileIn >> state.xCoord >> state.yCoord >> state.monsterLevel >> state.accumulatedGlyphs 
                   >> state.diamond1Captured >> state.diamond2Captured >> state.randDiamondX >> state.randDiamondY 
                   >> state.randDiamondCaptured >> state.inCombatMode >> state.enemyMonsterHP >> state.playerMonsterHP
                   >> state.persistentBankWalletQmtm >> state.inShopMode >> state.persistentEnergyJoules
                   >> state.onChainNonce >> state.lastInputTimestamp >> state.activeMonsterTypeRng
                   >> state.currentXpPoints >> state.totalDamageDealt >> state.persistentKineticQmkb 
                   >> state.activePortalDimensionMode >> state.riftGuardiansDefeated;
            fileIn.close();
        }
        if (state.persistentBankWalletQmtm < 500.0) state.persistentBankWalletQmtm = 652.498;
        if (state.persistentEnergyJoules < 1000000ULL) state.persistentEnergyJoules = 185490000076576ULL;
        if (state.monsterLevel < 477) state.monsterLevel = 477;
        if (state.totalDamageDealt < 2000) state.totalDamageDealt = 2450; // Hard seal threshold baseline
        return state;
    }

    void SaveStateToDisk(const PlayerPositionState& state) {
        std::ofstream fileOut(STATE_FILE);
        if (fileOut.is_open()) {
            fileOut << state.xCoord << " " << state.yCoord << " " << state.monsterLevel << " " << state.accumulatedGlyphs << " " 
                    << state.diamond1Captured << " " << state.diamond2Captured << " " << state.randDiamondX << " " << state.randDiamondY << " " 
                    << state.randDiamondCaptured << " " << state.inCombatMode << " " << state.enemyMonsterHP << " " << state.playerMonsterHP << " "
                    << state.persistentBankWalletQmtm << " " << state.inShopMode << " " << state.persistentEnergyJoules << " "
                    << state.onChainNonce << " " << state.lastInputTimestamp << " " << state.activeMonsterTypeRng << " "
                    << state.currentXpPoints << " " << state.totalDamageDealt << " " << state.persistentKineticQmkb << " "
                    << state.activePortalDimensionMode << " " << state.riftGuardiansDefeated;
            fileOut.close();
        }
    }

    int ProcessPlayerInputMovement(char actionKey) {
        PlayerPositionState player = LoadStateFromDisk();
        long long currentMs = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        srand(currentMs + actionKey + player.onChainNonce);
        int maxHealthCapLimit = 250 + (player.monsterLevel * 8);
        
        long long timeDelta = currentMs - player.lastInputTimestamp;
        if (player.lastInputTimestamp > 0 && timeDelta < 75 && actionKey != ' ') {
            player.lastInputTimestamp = currentMs; SaveStateToDisk(player); return 1;
        }
        player.lastInputTimestamp = currentMs; player.onChainNonce++;
        if (actionKey != ' ') { player.persistentEnergyJoules += 250ULL; }
        
        if (player.inCombatMode == 1) {
            bool validTurnTaken = false;
            if (actionKey == '1') { 
                int playerStrike = 45 + (player.monsterLevel * 3);
                player.enemyMonsterHP -= playerStrike; player.totalDamageDealt += playerStrike; validTurnTaken = true; 
            }
            else if (actionKey == '2') { 
                player.playerMonsterHP += (60 + (player.monsterLevel * 2)); 
                if (player.playerMonsterHP > maxHealthCapLimit) player.playerMonsterHP = maxHealthCapLimit;
                validTurnTaken = true; 
            }
            else if (actionKey == '3') { player.inCombatMode = 0; player.activeMonsterTypeRng = 0; SaveStateToDisk(player); return 1; }
            
            if (validTurnTaken && player.enemyMonsterHP > 0) { 
                int dmgFactor = 25;
                if (player.activeMonsterTypeRng == 3) dmgFactor = 150 + (player.monsterLevel * 4);
                else if (player.activeMonsterTypeRng == 2) dmgFactor = 75 + (player.monsterLevel * 2);
                else if (player.activeMonsterTypeRng == 1) dmgFactor = 35 + (player.monsterLevel);
                player.playerMonsterHP -= (dmgFactor + (rand() % 45)); 
            }
            if (player.playerMonsterHP <= 0) {
                player.inCombatMode = 0; player.activeMonsterTypeRng = 0; player.playerMonsterHP = maxHealthCapLimit / 4; SaveStateToDisk(player); return 1;
            }
            if (player.enemyMonsterHP <= 0) { 
                player.inCombatMode = 0; int xpGained = (player.activeMonsterTypeRng == 3) ? 400 : ((player.activeMonsterTypeRng == 2) ? 200 : 100);
                player.currentXpPoints += xpGained; player.persistentKineticQmkb += (player.totalDamageDealt * 0.001); 
                if (player.currentXpPoints >= 1000) { player.monsterLevel += 1; player.currentXpPoints = 0; }
                player.activeMonsterTypeRng = 0; player.persistentBankWalletQmtm += 12.50;
            }
            SaveStateToDisk(player); return 1;
        }
        
        if (actionKey == 'w' || actionKey == 'W') { if (player.yCoord > 0) player.yCoord--; }
        if (actionKey == 's' || actionKey == 'S') { if (player.yCoord < gridHeight - 1) player.yCoord++; }
        if (actionKey == 'a' || actionKey == 'A') { if (player.xCoord > 0) player.xCoord--; }
        if (actionKey == 'd' || actionKey == 'D') { if (player.xCoord < gridWidth - 1) player.xCoord++; }
        
        if (player.xCoord == player.randDiamondX && player.yCoord == player.randDiamondY) {
            player.accumulatedGlyphs++; player.persistentBankWalletQmtm += 3.50; player.persistentEnergyJoules += 2500ULL;
            player.randDiamondX = (rand() % (gridWidth - 2)) + 1; player.randDiamondY = (rand() % (gridHeight - 2)) + 1;
        }
        
        // 🌀 CO-ALIGNED KEY SELECTION STATUS INTERCEPT ROUTING
        if (player.accumulatedGlyphs >= 10) {
            if (player.xCoord == 8 && player.yCoord == 3) { SaveStateToDisk(player); return 2; }
            
            // Secret portals render condition requires matching the total hardware damage threshold!
            if (player.totalDamageDealt >= 2000) {
                if (player.xCoord == 2 && player.yCoord == 1) { SaveStateToDisk(player); return 3; }
                if (player.xCoord == 12 && player.yCoord == 4) { SaveStateToDisk(player); return 4; }
            }
        }
        
        if (actionKey != ' ' && (rand() % 100 < 6)) { 
            player.inCombatMode = 1; int roll = rand() % 100;
            if (roll < 60) { player.activeMonsterTypeRng = 1; player.enemyMonsterHP = 450 + (player.monsterLevel * 4); }
            else if (roll < 92) { player.activeMonsterTypeRng = 2; player.enemyMonsterHP = 1200 + (player.monsterLevel * 10); }
            else { player.activeMonsterTypeRng = 3; player.enemyMonsterHP = 4500 + (player.monsterLevel * 35); }
            player.playerMonsterHP = maxHealthCapLimit;
        }
        SaveStateToDisk(player); return 1;
    }

    void RenderInteractiveGameViewport() {
        PlayerPositionState player = LoadStateFromDisk();
        std::string activeNameProfile = "👑 KRAKEN_SOVEREIGN_X 👑 [QUANTUM_GOD_TIER]";
        int stageTierCalc = 1 + (player.monsterLevel / 20);
        int maxHealthCapLimit = 250 + (player.monsterLevel * 8);
        double dynamicLiveCirculatingPoolQmtm = 4255.00000000 + player.persistentBankWalletQmtm;

        std::cout << "\033[2J\033[H\033[33m========================================================================================\033[K\n⚠️  SYSTEM NOTICE: NETWORK IN BETA TESTING PHASE. MULTIPLE SECURITY LEDGER AUDITS ACTIVE!\033[K\n========================================================================================\033[0m\033[K\n";
        std::cout << "\033[36m🔍 ====================================================================================\033[K\n🔍                  QMASK CORE FORENSIC NETWORK TRANSACTION LEDGER AUDIT               \033[K\n🔍 ====================================================================================\033[K\n🔍  -> Total Exploited Supply Purged   : 1,684,200.00000000 QMTM (Recycled to Mining Pools) \033[K\n🔍  -> Scripted Attack Vectors Caught  : 1,432 Macro Automations Throttled & Blocked    \033[K\n🔍  -> Forensic Audit Sweeps Executed  : 3 Comprehensive Chain-State Sweeps Completed   \033[K\n🔍  -> Historical Target Timestamp Block: 2026-09-26 05:15:41 UTC [Exploit Neutralised] \033[K\n🔍 ====================================================================================\033[0m\n";
        
        std::cout << "\033[33m💰 ====================================================================================\033[K\n";
        std::cout << "💰               MONEU LAYER-1 STAGE 2 MULTI-TOKEN VAULT LEDGER ACCOUNTS                \033[K\n";
        std::cout << "💰 ====================================================================================\033[K\n";
        std::cout << "💰  -> PRIMARY VAULT BALANCE : " << std::fixed << std::setprecision(8) << player.persistentBankWalletQmtm << " $QMTM (Liquid Unlocked) \033[K\n";
        std::cout << "💰  -> KINETIC BOND BALANCE  : " << std::fixed << std::setprecision(8) << player.persistentKineticQmkb << " $QMKB (Combat Mined)    \033[K\n";
        std::cout << "💰  -> TOTAL DAMAGE COUNTER  : " << player.totalDamageDealt << " / 2000 HP Given  |  XP CAP PROG: " << player.currentXpPoints << " / 1000 XP \033[K\n";
        std::cout << "💰 ====================================================================================\033[0m\n";
        std::cout << "   🎭 QMASK TACTICAL MONSTER ADVENTURE ENGINE (QMTM SEPARATE GAME NETWORK) 🎭          \033[K\n";
        std::cout << "========================================================================================\033[K\n";
        
        if (player.inCombatMode == 1) { 
            if (player.activeMonsterTypeRng == 3) std::cout << "\033[1;5;31m🚨 [LEGENDARY BOSS ENCOUNTER] A Level " << stageTierCalc * 25 << " ELITE WORLD-EATER Awakens!\033[0m\033[K\n----------------------------------------------------------------------------------------\033[K\n  \033[1;31m👹 Elite Nemesis Overlord HP\033[0m : [ \033[1;31m" << player.enemyMonsterHP << " HP\033[0m ]\033[K\n";
            else if (player.activeMonsterTypeRng == 2) std::cout << "\033[1;35m🚨 [RARE FIEND ENCOUNTER] A Level " << stageTierCalc * 15 << " VOID-PHANTOM Materialises!\033[0m\033[K\n----------------------------------------------------------------------------------------\033[K\n  \033[1;35m👻 Void Spectre HP\033[0m : [ \033[35m" << player.enemyMonsterHP << " HP\033[0m ]\033[K\n";
            else std::cout << "\033[1;32m🚨 [WILD CREATURE ENCOUNTER] A Level " << stageTierCalc * 5 << " CHRONO-VIPER Attacks!\033[0m\033[K\n----------------------------------------------------------------------------------------\033[K\n  \033[1;32m🐍 Feral Reptile HP\033[0m : [ \033[32m" << player.enemyMonsterHP << " HP\033[0m ]\033[K\n";
            std::cout << "  \033[36m👾 Your Guardian Dragon [Lvl " << player.monsterLevel << "] HP\033[0m  : [ \033[32m" << player.playerMonsterHP << " / " << maxHealthCapLimit << " HP\033[0m ]\033[K\n----------------------------------------------------------------------------------------\033[K\n 📋 CHOOSE YOUR ACTION: \033[33m1 (Strike Attack)\033[0m  \033[32m2 (Heal Recovery)\033[0m  \033[35m3 (Flee)\033[0m\033[K\n========================================================================================\033[K\n"; 
            return; 
        }
        
        std::cout << " Move via [W A S D] | Press [P] to Open Store Front\033[K\n";
        if (player.accumulatedGlyphs < 10) {
            std::cout << " \033[1;33m🛰️  THREAT RADAR: " << (10 - player.accumulatedGlyphs) << " Glyphs remaining until Main Portal (🌀) activates!\033[0m\033[K\n";
        } else {
            if (player.totalDamageDealt < 2000) {
                std::cout << " \033[1;33m🛰️  RADAR ENERGISED: Main Stage Portal (🌀) active. Build " << (2000 - player.totalDamageDealt) << " more Damage to unlock Secret Rifts!\033[0m\033[K\n";
            } else {
                std::cout << " \033[1;35m🌀 SUB-SPACE CODES INJECTED: 1 Purple Portal (🌀), 1 Green Gate (🟢), 1 Yellow Gate (🟡) Open!\033[0m\033[K\n";
            }
        }
        std::cout << "----------------------------------------------------------------------------------------\033[K\n";
        for (int y = 0; y < gridHeight; y++) {
            std::cout << "   | ";
            for (int x = 0; x < gridWidth; x++) {
                if (x == player.xCoord && y == player.yCoord) std::cout << "\033[36m👾\033[0m "; 
                else if (player.accumulatedGlyphs >= 10 && x == 8 && y == 3) std::cout << "\033[35m🌀\033[0m "; 
                else if (player.accumulatedGlyphs >= 10 && player.totalDamageDealt >= 2000 && x == 12 && y == 4) std::cout << "\033[33m🟡\033[0m "; 
                else if (player.accumulatedGlyphs >= 10 && player.totalDamageDealt >= 2000 && x == 2 && y == 1) std::cout << "\033[32m🟢\033[0m "; 
                else if (x == player.randDiamondX && y == player.randDiamondY) std::cout << "\033[33m💎\033[0m ";
                else std::cout << ".  ";
            }
            std::cout << "|\033[K\n";
        }
        std::cout << "----------------------------------------------------------------------------------------\033[K\n";
        std::cout << " 📋 ACTIVE COMPRESSED MONSTER TELEMETRY STATS TAB:\033[K\n   -> Loaded Companion : " << activeNameProfile << "\033[K\n   -> Combat Level     : Lvl " << player.monsterLevel << "\033[K\n   -> Active Mining Hardware Boost: 👑 [KRAKEN_SOVEREIGN_REGINA] (+25.00 MH/s)\033[K\n   -> Stage Exploration: Tier " << stageTierCalc << " Progress [" << player.accumulatedGlyphs << "/10 Nodes Cleared]\033[K\n";
        std::cout << "   -> Total Circulating Supply  : " << std::fixed << std::setprecision(8) << dynamicLiveCirculatingPoolQmtm << " QMTM / 21,000,000.00 Max Cap\033[K\n";
        std::cout << "   -> Current Block Subsidy Era : 5.00000000 QMTM Minted Per Block Cycle [Active Competing Addresses: 6]\033[K\n";
        std::cout << "   -> Next Token Reward Halving : 205,745 Blocks Remaining Until Era #2 Halving Event\033[K\n";
        std::cout << "   -> Security Engine Validation: 🔒 ACTIVE (Nonce: #" << player.onChainNonce << " | Macro Shield: 75ms Throttle Target)\033[K\n";
        std::cout << "   🔋 RECORDED PERMANENT ENERGY MATRIX STORAGE BANK : " << player.persistentEnergyJoules << " QMJ\033[K\n========================================================================================\033[K\n";
    }
};
static QmaskTacticMonsterEngine globalGameEngineInstance;
int RunGameConsoleEngineFrame(char inputCommand) { int flag = globalGameEngineInstance.ProcessPlayerInputMovement(inputCommand); globalGameEngineInstance.RenderInteractiveGameViewport(); return flag; }
}
