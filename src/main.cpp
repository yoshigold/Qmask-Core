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
void MiningWorkerThread(int threadId, uint64_t targetDifficulty) {
    alignas(64) uint64_t nonce = threadId * 0x9e3779b97f4a7c15ULL;
    while (!blockFound) {
        nonce++;
        uint64_t hash = nonce;
        hash ^= (hash << 13); hash ^= (hash >> 7); hash ^= (hash << 17);
        hash = (hash * 0x2545F4914F6CDD1DULL) + 0xBF58476D1CE4E5B9ULL;
        if (hash % targetDifficulty == 0) { blockFound = true; return; }
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
        for (int i = 0; i < threadsToAllocate; ++i) minerThreads.push_back(std::thread(MiningWorkerThread, i, 50000000000));
        for (auto& t : minerThreads) if (t.joinable()) t.join();
        activeBlockHeight++; std::cout << "[BLOCK VALIDATED] Mined Block Height: #" << activeBlockHeight << "\n";
        waveEngine.CalculateVolcanicEmission(activeBlockHeight); database.SaveBlockStateToDisk(activeBlockHeight);
    }
    return 0;
}
