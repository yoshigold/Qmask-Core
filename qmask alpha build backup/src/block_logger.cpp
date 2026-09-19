#include "block_logger.h"
#include <iostream>
#include <fstream>

// 💾 LOGIC: Serializes and appends block history records cleanly to your local disk storage
bool QmaskBlockLogger::WriteBlockToLedger(int blockHeight, const std::string& blockRoot, double reward, double burned) {
    std::string fullPath = storageDir + storageFileName;
    
    // Open in append mode (std::ios::app) so new blocks stack sequentially without wiping old history
    std::ofstream file(fullPath, std::ios::app);

    // Fall back to saving directly in the project workspace folder if system paths aren't initialized yet
    if (!file.is_open()) {
        std::cout << "⚠️  Storage directory path uninitialized. Appending block to local workspace 'ledger.dat'...\n";
        file.open(storageFileName, std::ios::app);
        if (!file.is_open()) return false;
    }

    // Write a standardized chronological single-line history block packet
    file << "[BLOCK #" << blockHeight << "] ROOT: " << blockRoot 
         << " | REWARD: " << reward << " QMK | BURNED: " << burned << " QMK\n";

    file.close();
    return true;
}
