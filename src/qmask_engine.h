#ifndef QMASK_ENGINE_H
#define QMASK_ENGINE_H

#include <vector>
#include <string>

class QmaskEngine {
private:
    // 📂 The hidden system path where Qmask will look for your 32 MiB physical electron noise file
    const std::string entropyFilePath = "C:\\Users\\user\\AppData\\Local\\Qmask\\entropy.dat";

public:
    // 🛡️ FUNCTION A: Reads a raw, unpredictable burst of electron noise directly off your hard drive
    std::vector<unsigned char> ReadElectronNoise(size_t bytesToRead);

    // 🧲 FUNCTION B: Blends tx data + legacy signatures + electron noise into a 32-byte "Quantum Smoke Bomb" hash
    std::string CreateMaskedCommitment(const std::string& txData, const std::string& ecSignature, const std::vector<unsigned char>& noise);
};

#endif // QMASK_ENGINE_H
