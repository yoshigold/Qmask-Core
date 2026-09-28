#ifndef QMASK_WALLET_STORE_H
#define QMASK_WALLET_STORE_H

#include <string>

class QmaskWalletStore {
private:
    // ⚙️ Hardcoding the official directory path where Qmask stores user key files
    const std::string walletDir = "C:\\Users\\user\\AppData\\Local\\Qmask\\";
    const std::string walletFileName = "wallet.json";

public:
    // 🔑 Generates a secure, post-quantum 32-byte mnemonic wallet seed string
    std::string GenerateQuantumSeed();

    // 💾 Saves the encrypted wallet data configuration safely onto the local hard drive
    bool SaveWalletToDisk(const std::string& walletName, const std::string& address, const std::string& seed);
};

#endif // QMASK_WALLET_STORE_H
