#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <sstream>

namespace MONEU {
    int RunGameConsoleEngineFrame(char inputCommand);
}

int main(int argc, char* argv[]) {
    double baseWalletBalance = 9865.00000000;
    int gameX = 4, gameY = 2, monsterLvl = 477, glyphs = 0;
    int d1 = 0, d2 = 0, rx = 11, ry = 3, rc = 0, combat = 0, ehp = 0, php = 1200;
    double vaultQmtmBalance = 652.49800000; int shop = 0; 
    unsigned long long energyJoules = 185490000086380ULL;
    long long onChainNonce = 1017; long long lastInputTimestamp = 0; int activeMonsterTypeRng = 0;
    int currentXpPoints = 0; unsigned long long totalDamageDealt = 2450; double persistentKineticQmkb = 1.476;
    int activePortalDimensionMode = 0; int riftGuardiansDefeated = 0;

    std::ifstream gameStateIn("game_state.dat");
    if (gameStateIn.is_open()) {
        gameStateIn >> gameX >> gameY >> monsterLvl >> glyphs >> d1 >> d2 >> rx >> ry >> rc >> combat >> ehp >> php >> vaultQmtmBalance >> shop >> energyJoules >> onChainNonce >> lastInputTimestamp >> activeMonsterTypeRng >> currentXpPoints >> totalDamageDealt >> persistentKineticQmkb >> activePortalDimensionMode >> riftGuardiansDefeated;
        gameStateIn.close();
    }

    // 🔒 THE DEFINITIVE POINTER FIX: Explicitly targeting index 1 to pass inputs type-safely to the core engine
    if (argc > 1 && std::string(argv[1]) == "getblock") return 0;
    if (argc > 1 && std::string(argv[1]) == "--game-panel") {
        char inputChar = ' '; 
        if (argc > 2 && argv[2] != nullptr) { 
            inputChar = argv[2][0]; 
        }
        MONEU::RunGameConsoleEngineFrame(inputChar); 
        return 0;
    }

    long long currentHeight = 338719;
    if (argc > 1 && argv[1] != nullptr) { try { currentHeight = std::stoll(std::string(argv[1])); } catch (...) {} }
    
    std::cout << "MONEU Node Engine CLI initialized on Block Height #" << currentHeight << "\n";
    return 0;
}
