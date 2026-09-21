import os

cold_matrix_code = """#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <random>

#ifdef _WIN32
#include <direct.h>
#endif

class QmaskColdMatrixStorage {
public:
    void SaveBlockStateToDisk(int blockHeight) {
        std::string dirPath;
        #ifdef _WIN32
            dirPath = "qmask_mainnet_data";
            _mkdir(dirPath.c_str());
        #else
            dirPath = std::string(getenv("HOME")) + "/.qmask";
            mkdir(dirPath.c_str(), 0777); 
        #endif

        std::string filePath = dirPath + "/block_height.dat";
        std::ofstream saveFile(filePath, std::ios::trunc);
        if (saveFile.is_open()) {
            saveFile << blockHeight;
            saveFile.close();
            std::cout << "[COLD MATRIX] Hard-drive sync complete. Sealed block height #" << blockHeight << " safely to disk.\\n";
        }
    }

    int LoadSavedBlockState() {
        std::string dirPath;
        #ifdef _WIN32
            dirPath = "qmask_mainnet_data";
        #else
            dirPath = std::string(getenv("HOME")) + "/.qmask";
        #endif
        std::string filePath = dirPath + "/block_height.dat";
        
        std::ifstream readFile(filePath);
        int savedHeight = 13714; 
        if (readFile.is_open()) {
            readFile >> savedHeight;
            readFile.close();
            std::cout (&randomNoiseSeed), sizeof(randomNoiseSeed));
            }
            createNoise.close();
            std::cout << "[SGL SHIELD POOL] Initialized fresh CPU noise entropy file at: " << noisePath << "\\n";
        }
    }
};
"""

main_code = """#include <iostream>
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
    while (!blockFound) {
        uint64_t currentNonce = ++globalNonce;
        uint64_t hashResult = (currentNonce * 0x9e3779b97f4a7c15ULL) ^ (threadId * 1122334455ULL);
        if (hashResult % targetDifficulty == 0) {
            blockFound = true;
            return;
        }
    }
}

int main(int argc, char* argv[]) {
    std::cout  minerThreads;
        
        for (int i = 0; i < threadsToAllocate; ++i) {
            minerThreads.push_back(std::thread(MiningWorkerThread, i, currentDifficulty));
        }

        for (auto& t : minerThreads) {
            if (t.joinable()) t.join();
        }

        activeBlockHeight++;
        std::cout << "[BLOCK VALIDATED] Mined Block Height: #" << activeBlockHeight << "\\n";
        
        waveEngine.CalculateVolcanicEmission(activeBlockHeight);
        database.SaveBlockStateToDisk(activeBlockHeight);
        std::cout << "----------------------------------------------------------------\\n";
        
        sleep(2); 
    }

    return 0;
}
"""

with open("/mnt/c/Users/user/Desktop/Qmask-Core/src/cold_matrix.cpp", "w", encoding="utf-8") as f:
    f.write(cold_matrix_code)

with open("/mnt/c/Users/user/Desktop/Qmask-Core/src/main.cpp", "w", encoding="utf-8") as f:
    f.write(main_code)

print("🎯 [REPAIR STATUS] Both C++ files have been natively forced onto disk with 100% precision.")
