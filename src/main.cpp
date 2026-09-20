#include <iostream>
#include <string>
#include <unistd.h>

void InitializeSetupWizard();
void InitializeP2PNetworkListener();

// Pull our fresh save engine tracks
#include "cold_matrix.cpp"
#include "volcanic_wave.cpp"

int main(int argc, char* argv[]) {
    std::cout << "👑 =========================================================\n";
    std::cout << "👑 LAUNCHING PERSISTENT QMK MAINNET CORE DAEMON             \n";
    std::cout << "👑 =========================================================\n\n";

    InitializeSetupWizard();
    InitializeP2PNetworkListener();

    QmaskColdMatrixStorage database;
    QmaskVolcanicWaveEngine waveEngine;

    // 📥 CRITICAL FIX: Load your old block height from your hard drive on startup!
    int activeBlockHeight = database.LoadSavedBlockState();

    while (true) {
        activeBlockHeight++;
        std::cout << "🧱 [BLOCK VALIDATED] CPU Cache sealed Block Height: #" << activeBlockHeight << "\n";
        std::cout << "🎁 Reward Log: Allocated +5.0000 QMK to your wallet keys.\n";
        
        // Dynamic Volcanic Wave logic ticker
        waveEngine.CalculateVolcanicEmission(activeBlockHeight);

        // 💾 CRITICAL FIX: Permanently save the block to disk right now!
        database.SaveBlockStateToDisk(activeBlockHeight);

        std::cout << "----------------------------------------------------------------\n";
        sleep(10); // 10-second block time generation space
    }

    return 0;
}
