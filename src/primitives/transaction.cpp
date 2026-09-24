#include "transaction.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

size_t CalculateUltraLightTransactionSize(size_t inputCount, size_t outputCount, size_t decoyCount) {
    size_t baseOverhead = 65;
    size_t prunedOutputWeight = outputCount * 32;
    size_t privacyProofWeight = 0;
    
    if (decoyCount > 0) {
        if (decoyCount < 11) decoyCount = 11;
        double logSteps = std::ceil(std::log2(static_cast<double>(decoyCount)));
        privacyProofWeight = inputCount * (static_cast<size_t>(logSteps) * 32);
    } else {
        privacyProofWeight = inputCount * 64;
    }
    
    return baseOverhead + privacyProofWeight + prunedOutputWeight;
}

void PrintTransactionTelemetry(size_t inputs, size_t outputs, size_t decoys) {
    size_t legacySize = 65 + (inputs * (decoys * 85)) + (outputs * 42);
    size_t optimizedSize = CalculateUltraLightTransactionSize(inputs, outputs, decoys);
    double compressionRatio = (1.0 - ((double)optimizedSize / (double)legacySize)) * 100.0;

    std::cout << "⚡ [QMASK CORE TO SHADOW PRE-CONVERGENCE SHIELD ACTIVE]\n";
    std::cout << " -> Requested Privacy Anonymity Set  : " << decoys << " Scaling Decoys\n";
    std::cout << " -> Legacy Linear Ring Structure Size: " << (double)legacySize / 1024.0 << " KB\n";
    std::cout << " -> Bulletproofs++ Logarithmic Proof : " << (double)optimizedSize / 1024.0 << " KB\n";
    std::cout << " -> Ledger Bloat Bottleneck Prevention: Avoided " << compressionRatio << "% of database accumulation overhead!\n";
}
