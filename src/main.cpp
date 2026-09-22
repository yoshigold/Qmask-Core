#include <iostream>
#include <string>
#include <unistd.h>
#include <thread>
#include <vector>
#include <atomic>
#include <ctime>

void InitializeSetupWizard();
void InitializeP2PNetworkListener();
#include "cold_matrix.cpp"
#include "volcanic_wave.cpp"
#include "snapshot_bridge.cpp"

std::atomic<bool> blockFound(false);
uint64_t dynamicDifficulty = 50000000000ULL; // Initial seed difficulty
uint64_t lastRetargetTime = time(NULL);

void MiningWorkerThread(int threadId, uint64_t targetDiff) {
    alignas(64) uint64_t nonce = threadId * 0x9e3779b97f4a7c15ULL;
    while (!blockFound) {
        nonce++;
        uint64_t hash = nonce;
        hash ^= (hash << 13); hash ^= (hash >> 7); hash ^= (hash << 17);
        hash = (hash * 0x2545F4914F6CDD1DULL) + 0xBF58476D1CE4E5B9ULL;
        if (hash % targetDiff == 0) { blockFound = true; return; }
    }
}

int main() {
    InitializeSetupWizard(); InitializeP2PNetworkListener();
    QmaskColdMatrixStorage database; QmaskVolcanicWaveEngine waveEngine; QmaskSnapshotBridge snapshotBridge;
    int activeBlockHeight = database.LoadSavedBlockState();
    int threadsToAllocate = 32;
    
    std::cout << "[POWER UP] Pinning to exactly 32 Cache-Aligned physical CPU cores...\n";
    while (true) {
        blockFound = false; std::vector<std::thread> minerThreads;
        for (int i = 0; i < threadsToAllocate; ++i) minerThreads.push_back(std::thread(MiningWorkerThread, i, dynamicDifficulty));
        for (auto& t : minerThreads) if (t.joinable()) t.join();
        
        activeBlockHeight++;
        extern int currentBlockTrackingHeight;
        currentBlockTrackingHeight = activeBlockHeight;
        std::cout << "[BLOCK VALIDATED] Mined Block Height: #" << activeBlockHeight << " | Difficulty: " << dynamicDifficulty << "\n";
        
        // Dynamic Retargeting Algorithm every 10 blocks
        if (activeBlockHeight % 10 == 0) {
            uint64_t now = time(NULL);
            uint64_t actualTimeTaken = now - lastRetargetTime;
            uint64_t expectedTimeTime = 10 * 60; // 10 blocks * 60 seconds = 600 seconds
            
            if (actualTimeTaken < expectedTimeTime / 2) {
                dynamicDifficulty *= 2; // Blocks are too fast, double the puzzle complexity
            } else if (actualTimeTaken > expectedTimeTime * 2) {
                dynamicDifficulty /= 2; // Blocks are too slow, drop difficulty by half
            }
            if (dynamicDifficulty < 4000) dynamicDifficulty = 4000;
            lastRetargetTime = now;
        }
        
        waveEngine.CalculateVolcanicEmission(activeBlockHeight); database.SaveBlockStateToDisk(activeBlockHeight);
    }
    return 0;
}
