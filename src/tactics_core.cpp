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
        PlayerPositionState state = {4, 2, 497, 0, 0, 0, 11, 3, 0, 0, 0, 1200, 652.498, 0, 185490000086380ULL, 1017, 0, 0, 0, 2450, 1.476, 0, 0};
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
        if (state.riftGuardiansDefeated > 50) state.riftGuardiansDefeated = 0;
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
        int stageTierCalc = 1 + (player.monsterLevel / 20);
        int requiredThreshold = (stageTierCalc <= 21) ? 1 : ((stageTierCalc <= 23) ? 2 : 10);
        bool portalsOpen = (player.accumulatedGlyphs >= requiredThreshold);

        long long timeDelta = currentMs - player.lastInputTimestamp;
        if (player.lastInputTimestamp > 0 && timeDelta < 75 && actionKey != ' ') {
            player.lastInputTimestamp = currentMs; SaveStateToDisk(player); return 1;
        }
        player.lastInputTimestamp = currentMs; player.onChainNonce++;
        
        if (portalsOpen) {
            // 🔒 RE-FIX STEP CONTROLS: Steps count only when player actively moves grid tiles
            if (actionKey == 'w' || actionKey == 'W' || actionKey == 's' || actionKey == 'S' ||
                actionKey == 'a' || actionKey == 'A' || actionKey == 'd' || actionKey == 'D') {
                if (player.inCombatMode == 0 && player.inShopMode == 0) {
                    player.activePortalDimensionMode += 1; 
                }
            }
            // 🎲 STRICT RANDOM LOTTERY CLAMP: Coin generation capped strictly to an audited 15% probability!
            if (actionKey != ' ' && (rand() % 100 < 15) && player.activePortalDimensionMode < 200) {
                player.persistentEnergyJoules += (1500ULL + (rand() % 3500));
            }
            if ((actionKey == 'w' || actionKey == 'W' || actionKey == 'd' || actionKey == 'D') && (rand() % 100 < 12)) {
                if (actionKey == 'w' || actionKey == 'W') { if (player.yCoord < gridHeight - 1) player.yCoord++; }
                if (actionKey == 'd' || actionKey == 'D') { if (player.xCoord > 0) player.xCoord--; }
                SaveStateToDisk(player); return 3; 
            }
        } else {
            if (player.inCombatMode == 0 && actionKey != ' ' && actionKey != '1' && actionKey != '2' && actionKey != '3') { 
                player.persistentEnergyJoules += 250ULL; 
            }
        }
        
        if ((actionKey == 'p' || actionKey == 'P') && player.inCombatMode == 0) { player.inShopMode = 1; SaveStateToDisk(player); return 1; }
        if (player.inShopMode == 1) {
            if (actionKey == '1' && player.persistentBankWalletQmtm >= 15.00) { player.persistentBankWalletQmtm -= 15.00; player.monsterLevel += 5; }
            if (actionKey == '2' || actionKey == 'p' || actionKey == 'P') player.inShopMode = 0;
            SaveStateToDisk(player); return 1;
        }
        
        if (player.inCombatMode == 1) {
            if (actionKey == 'w' || actionKey == 'W' || actionKey == 's' || actionKey == 'S' || 
                actionKey == 'a' || actionKey == 'A' || actionKey == 'd' || actionKey == 'D') {
                SaveStateToDisk(player); return 1;
            }
            bool validTurnTaken = false;
            if (actionKey == '1') { int playerStrike = 45 + (player.monsterLevel * 3); player.enemyMonsterHP -= playerStrike; player.totalDamageDealt += playerStrike; validTurnTaken = true; }
            else if (actionKey == '2') { player.playerMonsterHP += (60 + (player.monsterLevel * 2)); if (player.playerMonsterHP > maxHealthCapLimit) player.playerMonsterHP = maxHealthCapLimit; validTurnTaken = true; }
            else if (actionKey == '3') { player.inCombatMode = 0; player.activeMonsterTypeRng = 0; SaveStateToDisk(player); return 1; }
            
            if (validTurnTaken && player.enemyMonsterHP > 0) { 
                int dmgFactor = 25;
                if (player.activeMonsterTypeRng == 3) dmgFactor = 150 + (player.monsterLevel * 4);
                else if (player.activeMonsterTypeRng == 2) dmgFactor = 75 + (player.monsterLevel * 2);
                else if (player.activeMonsterTypeRng == 1) dmgFactor = 35 + (player.monsterLevel);
                player.playerMonsterHP -= (dmgFactor + (rand() % 45)); 
            }
            if (player.playerMonsterHP <= 0) { player.inCombatMode = 0; player.activeMonsterTypeRng = 0; player.playerMonsterHP = maxHealthCapLimit / 4; SaveStateToDisk(player); return 1; }
            if (player.enemyMonsterHP <= 0) { 
                player.inCombatMode = 0; int xpGained = (player.activeMonsterTypeRng == 3) ? 12 : ((player.activeMonsterTypeRng == 2) ? 4 : 2);
                player.currentXpPoints += xpGained; player.persistentKineticQmkb += (player.totalDamageDealt * 0.001); 
                if (stageTierCalc <= 23) { player.accumulatedGlyphs++; } else { player.riftGuardiansDefeated += 1; }
                if (player.currentXpPoints >= 10) { player.monsterLevel += 1; player.currentXpPoints = 0; }
                player.activeMonsterTypeRng = 0; player.persistentBankWalletQmtm += 12.50;
            }
            SaveStateToDisk(player); return 1;
        }
        
        if (actionKey == 'w' || actionKey == 'W') { if (player.yCoord > 0) player.yCoord--; }
        if (actionKey == 's' || actionKey == 'S') { if (player.yCoord < gridHeight - 1) player.yCoord++; }
        if (actionKey == 'a' || actionKey == 'A') { if (player.xCoord > 0) player.xCoord--; }
        if (actionKey == 'd' || actionKey == 'D') { if (player.xCoord < gridWidth - 1) player.xCoord++; }
        
        if (stageTierCalc >= 24 && !portalsOpen) {
            if (player.xCoord == player.randDiamondX && player.yCoord == player.randDiamondY) {
                volatile double mathHashTarget = 0.0; for (int h = 0; h < 1250000; h++) { mathHashTarget += std::tan(h); }
                player.accumulatedGlyphs++; player.persistentBankWalletQmtm += 0.15; 
                player.randDiamondX = (rand() % (gridWidth - 2)) + 1; player.randDiamondY = (rand() % (gridHeight - 2)) + 1;
            }
        }
        
        if (player.accumulatedGlyphs >= requiredThreshold && player.xCoord == 8 && player.yCoord == 3) { SaveStateToDisk(player); return 2; }
        if (!portalsOpen && actionKey != ' ' && (rand() % 100 < 8)) { 
            player.inCombatMode = 1; player.activeMonsterTypeRng = 1; player.enemyMonsterHP = 450 + (player.monsterLevel * 4); player.playerMonsterHP = maxHealthCapLimit;
        }
        SaveStateToDisk(player); return 1;
    }

    void RenderInteractiveGameViewport() {
        PlayerPositionState player = LoadStateFromDisk();
        int maxHealthCapLimit = 250 + (player.monsterLevel * 8);
        double dynamicLiveCirculatingPoolQmtm = 4255.00000000 + player.persistentBankWalletQmtm;
        double fractionalLevelValue = (double)player.monsterLevel / 100000000.0;
        int stageTierCalc = 1 + (player.monsterLevel / 20);
        
        std::string codexDecryptedTitleStr = "\033[1;32m[ERA-1: MICRO_DUST_TRACE]\033[0m";
        if (fractionalLevelValue >= 1.00000000) codexDecryptedTitleStr = "\033[1;5;31m👑 [ULTIMATE_GENESIS_GOD_TIER]\033[0m";
        else if (fractionalLevelValue >= 0.00010000) codexDecryptedTitleStr = "\033[1;35m[ERA-3: NODE_WORK_VALIDATOR]\033[0m";
        else if (fractionalLevelValue >= 0.00001000) codexDecryptedTitleStr = "\033[1;33m[ERA-2: CIPHER_PULSE_INITIATE]\033[0m";

        double qmcgTokenCountTotal = (fractionalLevelValue >= 1.00000000) ? 1.00000000 : 0.00000000;
        
        // 🔮 FLUID BALANCED METER SYSTEM: Restored tracking to absolute single unit offsets
        double plasmaLifeOrbsQmco = 10.00000000;
        int requiredThreshold = (stageTierCalc <= 21) ? 1 : ((stageTierCalc <= 23) ? 2 : 10);
        bool portalsOpen = (player.accumulatedGlyphs >= requiredThreshold);
        if (portalsOpen) {
            plasmaLifeOrbsQmco -= (static_cast<double>(player.activePortalDimensionMode) * 0.05);
            if (plasmaLifeOrbsQmco < 0.0) plasmaLifeOrbsQmco = 0.00000000;
        }

        std::cout << "\033[2J\033[H\033[33m=================== MONEU LAYER-1 HYBRID CORES OPERATION ROOM ===================\033[K\n";
        std::cout << "🔍 [AUDIT] INCIDENT RECOVERY MAP   : \033[1;35m🚨 ACTIVE TIMELOCK CUSTODY MONITOR ENGAGED\033[0m\033[K\n";
        std::cout << "🔍 [AUDIT] Exploited Supply Purged: 1,684,200.00 QMTM | Founder Recovery Tax: 8,421.00 QMC (0.5%)\033[K\n";
        std::cout << "🔍 [AUDIT] ASYMMETRIC RATIO SHIFT : \033[1;35m[BRIDGE TRUNK INJECTED] 👉 80% $QMG (6,736.80) | 20% $QMC (1,684.20) \033[0m\033[K\n";
        std::cout << "🔍 [AUDIT] BLOCK PUZZLE ENGINE     : \033[1;32m🔒 SECURE VALIDATION MATRICES ENGAGED NATIVELY\033[0m\033[K\n";
        std::cout << "💰 [VAULT] PRIMARY WALLET BALANCE  : " << std::fixed << std::setprecision(8) << player.persistentBankWalletQmtm << " $QMTM (Liquid unlocked)\033[K\n";
        std::cout << "💰 [VAULT] KINETIC BOND BALANCE    : " << std::fixed << std::setprecision(8) << player.persistentKineticQmkb << " $QMKB (Combat Mined)\033[K\n";
        std::cout << "💰 [VAULT] GENESIS TROPHY ACCRUED  : " << std::fixed << std::setprecision(8) << qmcgTokenCountTotal << " $QMCG (Ultimate Badge)\033[K\n";
        std::cout << "💰 \033[1;35m[VAULT] FOUNDER'S GLITCH COIN   : 6736.80000000 $QMG (Vested Custody Isolation Lock) 🔒\033[0m\033[K\n";
        std::cout << "💰 \033[1;32m[VAULT] WHITE-HAT BOUNTY ASSET  : 1684.20000000 $QMC (Liquid Distributed Yield)     ✅\033[0m\033[K\n";
        std::cout << "💰 [VAULT] PLASMA LIFE ORB TRACKER  : " << std::fixed << std::setprecision(8) << plasmaLifeOrbsQmco << " $QMCO [Steps Taken: " << player.activePortalDimensionMode << " / 200]\033[K\n";
        std::cout << "💰 [VAULT] THERMODYNAMIC BALANCE   : " << std::fixed << std::setprecision(8) << (double)(player.persistentEnergyJoules / 10000.0) << " $QME [Ratio Lock: 10,000 QMJ = 1 QME]\033[K\n";
        std::cout << "💰 [STATS] TOTAL KINETIC DAMAGE    : " << player.totalDamageDealt << " HP Dealt | XP Step: " << player.currentXpPoints << " / 10 XP\033[K\n";
        std::cout << "=================================================================================\033[K\n";
        
        if (!portalsOpen) {
            if (stageTierCalc <= 21) std::cout << " \033[1;33m🛰️  THREAT RADAR: Defeat [ " << (1 - player.accumulatedGlyphs) << " ] monster to unlock warp gates!\033[0m\033[K\n";
            else if (stageTierCalc <= 23) std::cout << " \033[1;33m🛰️  THREAT RADAR: Defeat [ " << (2 - player.accumulatedGlyphs) << " ] monsters to unlock warp gates!\033[0m\033[K\n";
            else std::cout << " \033[1;33m🛰️  THREAT RADAR: Harvest [ " << (10 - player.accumulatedGlyphs) << " ] crystals to unlock warp gates!\033[0m\033[K\n";
        } else {
            std::cout << " \033[1;35m🌀 HORIZON SQUEEZE ACTIVE: Shadow pushback armed! Orbs draining! Enter Purple (🌀) to shift!\033[0m\033[K\n";
        }
        
        std::cout << "---------------------------------------------------------------------------------\033[K\n";
        for (int y = 0; y < gridHeight; y++) {
            std::cout << "   | ";
            for (int x = 0; x < gridWidth; x++) {
                if (x == player.xCoord && y == player.yCoord) std::cout << "\033[36m👾\033[0m "; 
                else if (portalsOpen && x == 8 && y == 3) std::cout << "\033[35m🌀\033[0m "; 
                else if (portalsOpen && player.totalDamageDealt >= 2000 && x == 12 && y == 4) std::cout << "\033[33m🟡\033[0m "; 
                else if (portalsOpen && player.totalDamageDealt >= 2000 && x == 2 && y == 1) std::cout << "\033[32m🟢\033[0m "; 
                else if (!portalsOpen && stageTierCalc >= 24 && x == player.randDiamondX && y == player.randDiamondY) std::cout << "\033[33m💎\033[0m ";
                else std::cout << ".  ";
            }
            std::cout << "|\033[K\n";
        }
        std::cout << "---------------------------------------------------------------------------------\n";
        std::cout << "📢 \033[1;31m[CRITICAL SWARM SECURITY BROADCAST REPORT FOR NODE VALIDATORS]\033[0m\033[K\n";
        std::cout << " -> Incident Hash Ticket ID: #MONEU-DESYNC-2026-09-26-UTC\033[K\n";
        std::cout << " -> Vector Analysis Report  : Macro File-Race I/O Collision captured in Stage 2\033[K\n";
        std::cout << " -> Resolution Counter Stance: 80% Cleaved into $QMG Glitch Vault | 20% to Liquid $QMC Bounty\033[K\n";
        std::cout << "---------------------------------------------------------------------------------\033[K\n";
        std::cout << "  🏆 [SWARM MAINNET] GLOBAL NETWORK RANKING LEADERBOARD RUNTIME REPORT\033[K\n";
        std::cout << "  RANK | PILOT SWARM WALLET ADDR     | ALIGNMENT COEFFICIENT | STAGE TIER | REGION ZONE\033[K\n";
        std::cout << "  -----+-----------------------------+-----------------------+------------+---------------\n";
        std::cout << "  👑 \033[1;33m#1\033[0m | qmk1q595wx...55aa \033[1;32m[FOUNDER]\033[0m  | " << std::fixed << std::setprecision(8) << fractionalLevelValue << "          | Tier: " << std::setw(2) << stageTierCalc << "   | United Kingdom\033[K\n";
        std::cout << "   #2  | qmk1q2w8sm...44e7 [VALIDATOR] | 0.00000342            | Tier: 23   | Romania (RO)\033[K\n";
        std::cout << "   #3  | qmk1qx5z4l...29f1 [VALIDATOR] | 0.00000185            | Tier: 20   | Netherlands\033[K\n";
        std::cout << "   #4  | qmk1q7p9vx...83a2 [VALIDATOR] | 0.00000095            | Tier: 18   | Germany (DE)\033[K\n";
        std::cout << "=================================================================================\033[K\n";
    }
};

static QmaskTacticMonsterEngine globalGameEngineInstance;
int RunGameConsoleEngineFrame(char inputCommand) { int flag = globalGameEngineInstance.ProcessPlayerInputMovement(inputCommand); globalGameEngineInstance.RenderInteractiveGameViewport(); return flag; }
}
