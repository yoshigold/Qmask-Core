#include "decay.h"
#include <iostream>
#include <cmath>
#include <iomanip>

// 🔥 THE INACTIVITY DECAY PROTOCOL CALCULATOR
double QmaskDecayEngine::CalculateDecayBalance(double originalBalance, int blocksSinceLastActive) {
    // If the address has been active within the 1,000 block grace period, no decay happens
    if (blocksSinceLastActive <= decayGracePeriodBlocks) {
        return originalBalance;
    }

    // Determine how many blocks the wallet has overrun past its safe grace limits
    int overdueBlocks = blocksSinceLastActive - decayGracePeriodBlocks;
    
    // Apply compounding exponential decay math over the inactive block duration
    double remainingFactor = std::pow(1.0 - decayRatePerBlock, overdueBlocks);
    double finalBalance = originalBalance * remainingFactor;

    // Enforce an absolute floor baseline so balances cannot drop below 0
    if (finalBalance < 0.0) finalBalance = 0.0;
    return finalBalance;
}

// 🚀 DECAY COMPONENT TEST BENCH