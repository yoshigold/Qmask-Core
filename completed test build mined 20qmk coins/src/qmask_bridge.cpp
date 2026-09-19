#include "qmask_engine.h"
#include <cstring>

// The extern "C" wrapper tells the compiler to output standard, universal machine link points
extern "C" {
    // 📡 THE RUST BRIDGE: Allows MONEU to pass text down to your C++ masking algorithm
    void Qmask_CreateMaskedCommitment_FFI(const char* txData, const char* ecSig, const unsigned char* noise, char* outputBuffer) {
        QmaskEngine engine;
        
        // Convert the raw incoming Rust character pointers into standard C++ strings
        std::string cppTxData(txData);
        std::string cppEcSig(ecSig);
        std::vector<unsigned char> cppNoise(noise, noise + 32);

        // Execute your native C++ masking mathematical calculation matrix
        std::string maskedResult = engine.CreateMaskedCommitment(cppTxData, cppEcSig, cppNoise);

        // Copy the final 32-character "Quantum Smoke Bomb" hash safely back up to Rust's memory loop
        std::strcpy(outputBuffer, maskedResult.c_str());
    }
}
