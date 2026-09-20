#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>

class QmaskColdMatrixStorage {
public:
    // 🧱 THE MAINNET SAVE VALVE: Writes block heights straight to persistent disk storage
    void SaveBlockStateToDisk(int blockHeight) {
        std::string dirPath = std::string(getenv("HOME")) + "/.moneu";
        std::string filePath = dirPath + "/block_height.dat";

        // Create the directory if it doesn't exist yet
        mkdir(dirPath.c_str(), 0777);

        // Commit the block height data down to your physical hard drive
        std::ofstream saveFile(filePath, std::ios::trunc);
        if (saveFile.is_open()) {
            saveFile << blockHeight;
            saveFile.close();
            std::cout << "💾 [COLD MATRIX] Hard-drive sync complete. Sealed block height #" << blockHeight << " safely to disk.\n";
        } else {
            std::cout << "⚠️  [STORAGE ERROR] Failed to pierce the VM barrier to write save file.\n";
        }
    }

    // 📥 THE BOOT STRAP LOADER: Reads your saved history when the node restarts
    int LoadSavedBlockState() {
        std::string filePath = std::string(getenv("HOME")) + "/.moneu/block_height.dat";
        std::ifstream readFile(filePath);
        int savedHeight = 13675; // Default baseline start if no file exists

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
