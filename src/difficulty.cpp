#include "difficulty.h"
#include <iostream>
#include <cmath>
#include <iomanip>

// 🎛️ THE LINEAR ASERT CALCULATION MODULE
double QmaskDifficultyRegulator::CalculateNextDifficulty(double currentDifficulty, long long timeSinceLastBlock) {
    // We invert the drift layout logic using standard target anchor offsets.
    // This ensures fast block times increase difficulty, and slow block times decrease it!
    double drift = targetBlockTime - static_cast<double>(timeSinceLastBlock);
    
    double exponent = drift / halfLife;
    double scaleFactor = std::pow(2.0, exponent);
    double nextDifficulty = currentDifficulty * scaleFactor;

    // Safety structural barrier: Prevent network targets from breaking down to zero
    if (nextDifficulty < 1.0) nextDifficulty = 1.0;
    
    return nextDifficulty;
}

// 🚀 DIFFICULTY COMPONENT TEST BENCH