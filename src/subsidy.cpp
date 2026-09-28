#include "subsidy.h"
#include <iostream>
#include <cmath>
#include <iomanip>

// 🪙 THE HALVING SUBSIDY LOGIC Engine
double QmaskSubsidyEngine::GetCurrentBlockReward(int currentBlockHeight) {
    // Determine how many halvings have occurred via integer division
    int halvingCount = currentBlockHeight / halvingIntervalBlocks;

    // Safety constraint: If the blockchain runs for decades, drop the reward to 0 once it hits step 64
    if (halvingCount >= 64) return 0.0;

    // Execute the exponential division loop to calculate the active reward step
    double currentReward = initialBlockReward / std::pow(2.0, halvingCount);
    return currentReward;
}

// 🚀 SUBSIDY COMPONENT TEST BENCH