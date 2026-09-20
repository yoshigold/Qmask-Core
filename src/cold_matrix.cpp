#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>

#ifdef _WIN32
#include <direct.h>
#endif

class QmaskColdMatrixStorage {
public:
    // 🧱 THE MAINNET SAVE VALVE: Writes block heights straight to persistent disk storage
    void SaveBlockStateToDisk(int blockHeight) {
        std::string dirPath;
        
        #ifdef _WIN32
            dirPath = "qmask_mainnet_data";
            _mkdir(dirPath.c_str());
        #else
            // SOVEREIGN PATH SEPARATION: Move to its own native hidden directory folder
            dirPath = std::string(getenv("HOME")) + "/.qmask";
            mkdir(dirPath.c_str(), 0777); 
        #endif

        std::string filePath = dirPath + "/block_height.dat";

        std::ofstream saveFile(filePath, std::ios::trunc);
        if (saveFile.is_open()) {
            saveFile << blockHeight;
            saveFile.close();
            std::cout << "💾 [COLD MATRIX] Hard-drive sync complete. Sealed block height #" << blockHeight << " safely to disk.\n";
        } else {
            std::cout << "⚠️  [STORAGE ERROR] Failed to pierce the system barrier to write save file.\n";
        }
    }

    int LoadSavedBlockState() {
        #ifdef _WIN32
            std::string filePath = "qmask_mainnet_data/block_height.dat";
        #else
            std::string filePath = std::string(getenv("HOME")) + "/.qmask/block_height.dat";
        #endif
        
        std::ifstream readFile(filePath);
        int savedHeight = 13714; // Default baseline start if no file exists

        if (readFile.is_open()) {
            readFile >> savedHeight;
            readFile.close();
            std::cout << "📥 [MAINNET BOOT] Found historical save ledger. Resuming sync from block height #" << savedHeight << "\n";
        } else {
            std::cout << "🧱 [GENESIS BOOT] No prior database save spotted. Initializing fresh node track.\n";
        }
        return savedHeight;
    }
};
