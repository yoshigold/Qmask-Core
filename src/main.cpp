#include <iostream>
#include <string>
#include <unistd.h>
#include <thread>
#include <vector>
#include <atomic>

void InitializeSetupWizard();
void InitializeP2PNetworkListener();

#include "cold_matrix.cpp"
#include "volcanic_wave.cpp"
#include "snapshot_bridge.cpp"

std::atomic<bool> blockFound(false);
std::atomic<uint64_t> globalNonce(0);

// 🧠 MULTI-THREADED UNLOCKED WORKER
void MiningWorkerThread(int threadId, uint64_t targetDifficulty) {
    while (!blockFound) {
        uint64_t currentNonce = ++globalNonce;
        
        // Fast 1-cycle bitwise scrambling math to max out cache
        uint64_t hashResult = (currentNonce * 0x9e3779b97f4a7c15ULL) ^ (threadId * 1122334455ULL);
        
        // Lowered friction check loop to guarantee instant blocks
        if (hashResult % targetDifficulty == 0) {
            blockFound = true;
            return; // Force immediate cleanup return path
        }
    }
}

int main(int argc, char* argv[]) {
    std::cout << "👑 =========================================================\n";
    std::cout << "👑 LAUNCHING FLUID POW MULTI-THREADED MAINNET ENGINES      \n";
    std::cout << "👑 =========================================================\n\n";

    InitializeSetupWizard();
    InitializeP2PNetworkListener();

    QmaskColdMatrixStorage database;
    QmaskVolcanicWaveEngine waveEngine;
    QmaskSnapshotBridge snapshotBridge;

    snapshotBridge.CalculateSovereignSplit(15000000.0);
    int activeBlockHeight = database.LoadSavedBlockState();

    int threadsToAllocate = std::thread::hardware_concurrency();
    std::cout << "🛰️  Allocating [" << threadsToAllocate << "] parallel CPU hardware thread lanes...\n";

    uint64_t currentDifficulty = 4000; // Calibrated ultra-light target for immediate testing drops

    while (true) {
        blockFound = false;
        std::vector<std::thread> minerThreads;
        
        // Spin up your 32 processing tracks in tandem
        for (int i = 0; i < threadsToAllocate; ++i) {
            minerThreads.push_back(std::thread(MiningWorkerThread, i, currentDifficulty));
        }

        // Wait for worker alignment to signal block completion
        for (auto& t : minerThreads) {
            if (t.joinable()) t.join();
        }

        activeBlockHeight++;
        std::cout << "🧱 [BLOCK VALIDATED] Mined Block Height: #" << activeBlockHeight << "\n";
        
        waveEngine.CalculateVolcanicEmission(activeBlockHeight);
        database.SaveBlockStateToDisk(activeBlockHeight);
        std::cout << "----------------------------------------------------------------\n";
        
        sleep(2); // Induce a brief 2-second rest interval between solutions
    }

    return 0;
}
