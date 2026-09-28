#ifndef QMASK_BLOCK_LOGGER_H
#define QMASK_BLOCK_LOGGER_H

#include <string>

class QmaskBlockLogger {
private:
    // ⚙️ Hardcoding the structural ledger data storage directory path
    const std::string storageDir = "C:\\Users\\user\\AppData\\Local\\Qmask\\";
    const std::string storageFileName = "ledger.dat";

public:
    // 💾 Logs a permanent chronological record of a sealed block onto the local disk drive
    bool WriteBlockToLedger(int blockHeight, const std::string& blockRoot, double reward, double burned);
};

#endif // QMASK_BLOCK_LOGGER_H
