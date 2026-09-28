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
    long long onChainNonce; long long lastInputTimestamp; int activeMonsterTypeRng;
    int currentXpPoints;          
    unsigned long long totalDamageDealt; 
    double persistentKineticQmkb; 
    int activePortalDimensionMode;
    int riftGuardiansDefeated;   
};
class QmaskTacticMonsterEngine {
private:
    int gridWidth = 16; int gridHeight = 6; const std::string STATE_FILE = "game_state.dat";
public:
    PlayerPositionState LoadStateFromDisk() {
        PlayerPositionState state = {4, 2, 537, 0, 0, 0, 11, 3, 0, 0, 0, 1200, 1173.180, 0, 185490002182370ULL, 1017, 0, 0, 0, 40994, 1.476, 0, 0};
        std::ifstream fileIn(STATE_FILE);
        if (fileIn.is_open()) {
            fileIn >> state.xCoord >> state.yCoord >> state.monsterLevel >> state.accumulatedGlyphs >> state.diamond1Captured >> state.diamond2Captured >> state.randDiamondX >> state.randDiamondY >> state.randDiamondCaptured >> state.inCombatMode >> state.enemyMonsterHP >> state.playerMonsterHP >> state.persistentBankWalletQmtm >> state.inShopMode >> state.persistentEnergyJoules >> state.onChainNonce >> state.lastInputTimestamp >> state.activeMonsterTypeRng >> state.currentXpPoints >> state.totalDamageDealt >> state.persistentKineticQmkb >> state.activePortalDimensionMode >> state.riftGuardiansDefeated;
            fileIn.close();
        }
        return state;
    }
    void SaveStateToDisk(const PlayerPositionState& state) {
        std::ofstream fileOut(STATE_FILE);
        if (fileOut.is_open()) {
            fileOut << state.xCoord << " " << state.yCoord << " " << state.monsterLevel << " " << state.accumulatedGlyphs << " " << state.diamond1Captured << " " << state.diamond2Captured << " " << state.randDiamondX << " " << state.randDiamondY << " " << state.randDiamondCaptured << " " << state.inCombatMode << " " << state.enemyMonsterHP << " " << state.playerMonsterHP << " " << state.persistentBankWalletQmtm << " " << state.inShopMode << " " << state.persistentEnergyJoules << " " << state.onChainNonce << " " << state.lastInputTimestamp << " " << state.activeMonsterTypeRng << " " << state.currentXpPoints << " " << state.totalDamageDealt << " " << state.persistentKineticQmkb << " " << state.activePortalDimensionMode << " " << state.riftGuardiansDefeated;
            fileOut.close();
        }
    }
    int ProcessPlayerInputMovement(char actionKey) {
        PlayerPositionState player = LoadStateFromDisk();
        long long currentMs = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        srand(currentMs + actionKey + player.onChainNonce);
        int tier = 1 + (player.monsterLevel / 20); int cap = 250 + (player.monsterLevel * 6);
        bool isDir = (actionKey=='w'||actionKey=='W'||actionKey=='s'||actionKey=='S'||actionKey=='a'||actionKey=='A'||actionKey=='d'||actionKey=='D');
        int reqKills = (tier <= 20) ? 3 : ((tier <= 25) ? 5 : 10);
        bool phase1 = (player.riftGuardiansDefeated >= reqKills); bool phase2 = (player.accumulatedGlyphs >= 10);
        double damp = 2.0 / (2.0 + std::pow(static_cast<double>(tier), 1.2));

        if ((actionKey == 'i' || actionKey == 'I') && player.inCombatMode == 0) {
            player.inShopMode = (player.inShopMode == 2) ? 0 : 2; SaveStateToDisk(player); return 1;
        }
        if (player.inShopMode == 2) {
            if (actionKey == '1' && player.diamond1Captured > 0) { player.diamond1Captured--; player.playerMonsterHP += 500; if (player.playerMonsterHP > cap) player.playerMonsterHP = cap; }
            else if (actionKey == '2' || isDir) { player.inShopMode = 0; }
            SaveStateToDisk(player); return 1;
        }
        if ((actionKey == 'k' || actionKey == 'K') && player.inCombatMode == 0) {
            player.inShopMode = (player.inShopMode == 3) ? 0 : 3; SaveStateToDisk(player); return 1;
        }
        if (player.inShopMode == 3) {
            if (actionKey == '1' && player.currentXpPoints >= 2) { player.currentXpPoints -= 2; player.monsterLevel += 5; }
            else if (actionKey == '2' || isDir) { player.inShopMode = 0; }
            SaveStateToDisk(player); return 1;
        }

        if (player.inCombatMode == 1) {
            if (isDir) { SaveStateToDisk(player); return 1; }
            bool valid = false; int baseStrike = 35 + (player.monsterLevel * 1); 
            if (actionKey == '1') { player.enemyMonsterHP -= baseStrike; player.totalDamageDealt += baseStrike; valid = true; }
            else if (actionKey == '2') { player.playerMonsterHP += (150 + (tier * 5)); if (player.playerMonsterHP > cap) player.playerMonsterHP = cap; valid = true; }
            else if (actionKey == '4' && player.monsterLevel >= 520) { int plasmaStrike = baseStrike * 3; player.enemyMonsterHP -= plasmaStrike; player.totalDamageDealt += plasmaStrike; valid = true; }
            else if (actionKey == '5' && player.monsterLevel >= 535) { player.playerMonsterHP += 600; if (player.playerMonsterHP > cap) player.playerMonsterHP = cap; valid = true; }
            else if (actionKey == '3') { player.inCombatMode = 0; player.activeMonsterTypeRng = 0; SaveStateToDisk(player); return 1; }
            
            if (valid && player.enemyMonsterHP > 0) {
                int damageReductionFactor = (actionKey == '5') ? 12 : 25;
                player.playerMonsterHP -= (damageReductionFactor + (rand() % 20) + (tier * 2));
            }
            if (player.playerMonsterHP <= 0) { player.inCombatMode = 0; player.playerMonsterHP = cap / 2; SaveStateToDisk(player); return 1; }
            if (player.enemyMonsterHP <= 0) { 
                player.inCombatMode = 0; if (!phase1) player.riftGuardiansDefeated += 1; 
                player.persistentBankWalletQmtm += (25.00 * (player.activeMonsterTypeRng == 3 ? 4.0 : 1.0) * damp);
                if ((rand() % 100) < (player.activeMonsterTypeRng == 1 ? 20 : 50)) player.diamond1Captured += 1;
                player.currentXpPoints += (player.activeMonsterTypeRng == 3 ? 5 : 2); player.activeMonsterTypeRng = 0; 
            }
            SaveStateToDisk(player); return 1;
        }
        if (actionKey == 'w' || actionKey == 'W') { if (player.yCoord > 0) player.yCoord--; }
        if (actionKey == 's' || actionKey == 'S') { if (player.yCoord < gridHeight - 1) player.yCoord++; }
        if (actionKey == 'a' || actionKey == 'A') { if (player.xCoord > 0) player.xCoord--; }
        if (actionKey == 'd' || actionKey == 'D') { if (player.xCoord < gridWidth - 1) player.xCoord++; }
        if (phase1 && !phase2 && player.xCoord == player.randDiamondX && player.yCoord == player.randDiamondY) { player.accumulatedGlyphs += 5; player.persistentBankWalletQmtm += (75.00 * damp); player.randDiamondX = (rand() % (gridWidth - 2)) + 1; player.randDiamondY = (rand() % (gridHeight - 2)) + 1; }
        if (phase2 && player.xCoord == 8 && player.yCoord == 3) { SaveStateToDisk(player); return 2; }
        
        if (!phase1 && isDir && (rand() % 100 < 14)) { 
            player.inCombatMode = 1; int roll = rand() % 100;
            if (roll < 60) { player.activeMonsterTypeRng = 1; player.enemyMonsterHP = 350 + (rand() % 200); } 
            else if (roll < 90) { player.activeMonsterTypeRng = 2; player.enemyMonsterHP = 1200 + (rand() % 800); } 
            else { player.activeMonsterTypeRng = 3; player.enemyMonsterHP = 8000 + (player.monsterLevel * tier * 1.5); } 
            player.playerMonsterHP = cap; 
        }
        SaveStateToDisk(player); return 1;
    }
    void RenderInteractiveGameViewport() {
        PlayerPositionState player = LoadStateFromDisk();
        int cap = 250 + (player.monsterLevel * 6); double frac = (double)player.monsterLevel / 100000000.0; int tier = 1 + (player.monsterLevel / 20);
        int requiredKills = (tier <= 20) ? 3 : ((tier <= 25) ? 5 : 10);
        bool phase1 = (player.riftGuardiansDefeated >= requiredKills); bool phase2 = (player.accumulatedGlyphs >= 10);

        std::string evolutionForm = "Starter Dragon Pupa";
        if (player.monsterLevel >= 535) evolutionForm = "👑 [KRAKEN HORIZON LEVIATHAN] (MAX EVOLUTION)";
        else if (player.monsterLevel >= 500) evolutionForm = "Sovereign Glitch-Drake Elite";

        std::cout << "\033[2J\033[H\033[33m=================== MONEU LAYER-1 HYBRID CORES OPERATION ROOM ===================\033[K\n";
        std::cout << "🔍 [AUDIT] INCIDENT RECOVERY MAP   : \033[1;35m🚨 ACTIVE TIMELOCK CUSTODY MONITOR ENGAGED\033[0m\033[K\n";
        std::cout << "🔍 [AUDIT] Exploited Supply Purged: 1,684,200.00 QMTM | Founder Recovery Tax: 8,421.00 QMC (0.5%)\033[K\n";
        std::cout << "🔍 [AUDIT] ASYMMETRIC RATIO SHIFT : \033[1;35m[BRIDGE TRUNK INJECTED] 👉 80% $QMG (6,736.80) | 20% $QMC (1,684.20) \033[0m\033[K\n";
        std::cout << "🔍 [AUDIT] BLOCK PUZZLE ENGINE     : \033[1;32m🔒 COMPLETE WSL DIAGNOSTIC RUNTIME STABILIZED\033[0m\033[K\n";
        std::cout << "💰 [VAULT] PRIMARY WALLET BALANCE  : " << std::fixed << std::setprecision(8) << player.persistentBankWalletQmtm << " $QMTM\033[K\n";
        std::cout << "💰 [VAULT] KINETIC BOND BALANCE    : " << std::fixed << std::setprecision(8) << player.persistentKineticQmkb << " $QMKB\033[K\n";
        std::cout << "💰 \033[1;35m[VAULT] FOUNDER'S GLITCH COIN   : 6736.80000000 $QMG (Vested Custody Isolation Lock) 🔒\033[0m\033[K\n";
        std::cout << "💰 \033[1;32m[VAULT] WHITE-HAT BOUNTY ASSET  : 1684.20000000 $QMC (Liquid Distributed Yield)     ✅\033[0m\033[K\n";
        std::cout << "💰 [VAULT] PLASMA LIFE ORB TRACKER  : 10.00000000 $QMCO [Steps Taken: " << player.activePortalDimensionMode << " / 200]\033[K\n";
        std::cout << "💰 [VAULT] THERMODYNAMIC BALANCE   : " << std::fixed << std::setprecision(8) << (double)(player.persistentEnergyJoules / 10000.0) << " $QME [Ratio Lock: 10,000 QMJ = 1 QME]\033[K\n";
        std::cout << "💰 [STATS] TOTAL KINETIC DAMAGE    : " << player.totalDamageDealt << " HP Dealt | XP Step: " << player.currentXpPoints << " / 10 XP\033[K\n";
        std::cout << "=================================================================================\033[K\n";
        
        if (player.inShopMode == 3) {
            std::cout << "\033[1;33m🌟 [SOVEREIGN COMPANION TALENT ALLOCATION SHIFT] Total Training Bank: [ " << player.currentXpPoints << " XP ]\n";
            std::cout << "  👉 Press 1 : Allocate 2 XP Shards -> Enhance Attack Rating (+5 Base Power Rating Levels)\n";
            std::cout << "  👉 Press 2 : Close Skill Matrix and Return back to active grid cells\033[0m\n";
        }
        else if (player.inShopMode == 2) {
            std::cout << "\033[1;36m🎒 [SOVEREIGN COMPANION INVENTORY BAG] Browse your collected resources below:\n";
            std::cout << "  👉 Press 1 : Consume Chrono-Potion (" << player.diamond1Captured << " Left) | Instantly restores +500 HP!\n";
            std::cout << "  👉 Press 2 : Close Companion Bag and Return to active sector grid\033[0m\n";
        }
        else if (player.inCombatMode == 1) {
            std::string rLabel = (player.activeMonsterTypeRng == 1) ? "🟢 EASY" : ((player.activeMonsterTypeRng == 2) ? "🟡 MEDIUM" : "🔴 HARDCORE BOSS");
            std::cout << "⚔️  [PLAYER HUD]        : " << evolutionForm << " | HP: [ " << player.playerMonsterHP << " / " << cap << " ]\n";
            std::cout << "🌾 [WILD ENCOUNTER]     : Rank [ " << rLabel << " ] | Foe HP: [ " << player.enemyMonsterHP << " ]\n";
            std::cout << " 👉 SKILLS ACTIONS BAR  : 1 (Strike) | 2 (Heal) | 4 (Plasma Flare) | 5 (Barrier) | 3 (🏃 FLEE)\n";
        }
        else {
            std::string zoneLabel = (tier <= 20) ? "🟢 EASY FRONTIER" : ((tier <= 25) ? "🟡 MEDIUM FORGE" : "🔴 HARDCORE DEPTHS");
            if (!phase1) { std::cout << " \033[1;33m🌾 CAMPAIGN FIELD [ " << zoneLabel << " - TIER " << tier << " ]: Clear [ " << (requiredKills - player.riftGuardiansDefeated) << " ] field encounters! [K: Talents | I: Bag]\033[0m\n"; }
            else if (!phase2) { std::cout << " \033[1;32m💎 EXTRACTION SQUAD [ TIER " << tier << " ]: Field clear! Extract Diamond Shards (💎) to charge portal! [K: Talents]\033[0m\n"; }
            else { std::cout << " \033[1;35m🌀 HORIZON SQUEEZE ACTIVE: Sector cleared! Navigate to Purple Gateway (🌀) at 8,3!\033[0m\n"; }
        }
        std::cout << "---------------------------------------------------------------------------------\033[K\n";
        
        if (player.inShopMode == 2) {
            std::cout << "   | [💼 SLOT 01] : Chrono-Potion       x" << player.diamond1Captured << " (Restores HP)      |\n";
            std::cout << "   | [💼 SLOT 02] : Phoenix Elixir      x0 (Immature Drop)        |\n";
            std::cout << "   | [💼 SLOT 03] : Kinetic Shards      x0 (Forging Resource)     |\n";
            std::cout << "   | Inventory Capacity: [ " << player.diamond1Captured << " / 20 items ] Securely Anchored on-chain |\n";
        } else if (player.inShopMode == 3) {
            std::cout << "   | [🌟 TREE ROW 01] : Multiplier Strike Core   Level " << player.monsterLevel << " (Spend 2 XP to increase)   |\n";
            std::cout << "   | [🌟 TREE ROW 02] : Kinetic Barrier Armor   Level 00 (Locked Milestone)            |\n";
            std::cout << "   | [🌟 TREE ROW 03] : Pouch Expansion Slot    Level 01 (Max capacity locked)          |\n";
            std::cout << "   | Current Training Points Held: [ " << player.currentXpPoints << " XP Shards available ]                   |\n";
        } else {
            for (int y = 0; y < gridHeight; y++) {
                std::cout << "   | ";
                for (int x = 0; x < gridWidth; x++) {
                    if (x == player.xCoord && y == player.yCoord) std::cout << "\033[36m👾\033[0m "; 
                    else if (phase2 && x == 8 && y == 3) std::cout << "\033[35m🌀\033[0m "; 
                    else if (phase1 && !phase2 && x == player.randDiamondX && y == player.randDiamondY) std::cout << "\033[33m💎\033[0m "; 
                    else std::cout << ".  ";
                } std::cout << "|\033[K\n";
            }
        }
        std::cout << "---------------------------------------------------------------------------------\n";
        std::cout << "📢 \033[1;31m[CRITICAL SWARM SECURITY BROADCAST REPORT FOR NODE VALIDATORS]\033[0m\033[K\n";
        std::cout << " -> Incident Hash Ticket ID: #MONEU-DESYNC-2026-09-26-UTC\033[K\n";
        std::cout << " -> Vector Analysis Report  : Macro File-Race I/O Collision captured in Stage 2\033[K\n";
        std::cout << "---------------------------------------------------------------------------------\033[K\n";
        std::cout << "  🏆 [SWARM MAINNET] GLOBAL NETWORK RANKING LEADERBOARD REPORT\033[K\n";
        std::cout << "  RANK | PILOT SWARM WALLET ADDR     | ALIGNMENT COEFFICIENT | STAGE TIER | REGION ZONE\033[K\n";
        std::cout << "  -----+-----------------------------+-----------------------+------------+---------------\n";
        std::cout << "  👑 \033[1;33m#1\033[0m | qmk1q595wx...55aa \033[1;32m[FOUNDER]\033[0m  | " << std::fixed << std::setprecision(8) << frac << "          | Tier: " << std::setw(2) << tier << "   | United Kingdom\033[K\n";
        std::cout << "   #2  | qmk1q2w8sm...44e7 [VALIDATOR] | 0.00000342            | Tier: 23   | Romania (RO)\033[K\n";
        std::cout << "   #3  | qmk1qx5z4l...29f1 [VALIDATOR] | 0.00000185            | Tier: 20   | Netherlands\033[K\n";
        std::cout << "   #4  | qmk1q7p9vx...83a2 [VALIDATOR] | 0.00000095            | Tier: 18   | Germany (DE)\033[K\n";
        std::cout << "=================================================================================\033[K\n";
    }
};
static QmaskTacticMonsterEngine engine;
int RunGameConsoleEngineFrame(char c) { int f = engine.ProcessPlayerInputMovement(c); engine.RenderInteractiveGameViewport(); return f; }
}
