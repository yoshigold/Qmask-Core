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
uint64_t dynamicDifficulty = 50000000000ULL; 
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

int main(int argc, char* argv[]) {
    InitializeSetupWizard(); InitializeP2PNetworkListener();
    QmaskColdMatrixStorage database; QmaskVolcanicWaveEngine waveEngine; QmaskSnapshotBridge snapshotBridge;
    int activeBlockHeight = database.LoadSavedBlockState();
    
    // Detect hardware maximum threads dynamically as the baseline fallback
    unsigned int maxHardwareThreads = std::thread::hardware_concurrency();
    if (maxHardwareThreads == 0) maxHardwareThreads = 32; // Safety fallback for Threadripper PRO
    
    int threadsToAllocate = maxHardwareThreads;
    
    // Parse custom manual input arguments if provided on startup
    if (argc > 1) {
        try {
            int customInput = std::stoi(argv[1]);
            if (customInput > 0 && customInput <= (int)maxHardwareThreads) {
                threadsToAllocate = customInput;
            } else {
                std::cout << "[WARNING] Input thread count out of bounds. Defaulting to max system capacity.\n";
            }
        } catch (...) {
            std::cout << "[WARNING] Invalid thread argument string parsed. Defaulting to max system capacity.\n";
        }
    }
    
    std::cout << "[POWER UP] Engaging exactly " << threadsToAllocate << " Cache-Aligned physical CPU cores...\n";
    while (true) {
        blockFound = false; std::vector<std::thread> minerThreads;
        for (int i = 0; i < threadsToAllocate; ++i) minerThreads.push_back(std::thread(MiningWorkerThread, i, dynamicDifficulty));
        for (auto& t : minerThreads) if (t.joinable()) t.join();
        
        activeBlockHeight++;
        std::cout << "[BLOCK VALIDATED] Mined Block Height: #" << activeBlockHeight << " | Difficulty: " << dynamicDifficulty << "\n";
        extern int currentBlockTrackingHeight;
        currentBlockTrackingHeight = activeBlockHeight;
        
        if (activeBlockHeight % 10 == 0) {
            uint64_t now = time(NULL);
            uint64_t actualTimeTaken = now - lastRetargetTime;
            uint64_t expectedTimeTime = 10 * 60; 
            
            if (actualTimeTaken < expectedTimeTime / 2) {
                dynamicDifficulty *= 2; 
            } else if (actualTimeTaken > expectedTimeTime * 2) {
                dynamicDifficulty /= 2; 
            }
            if (dynamicDifficulty < 4000) dynamicDifficulty = 4000;
            lastRetargetTime = now;
        }
        
        waveEngine.CalculateVolcanicEmission(activeBlockHeight); database.SaveBlockStateToDisk(activeBlockHeight);
    }
    return 0;
}
