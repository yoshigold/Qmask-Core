#include <iostream>
#include <string>
#include <cstdint>

bool VerifyTransactionMaturity(int txSourceBlockHeight, int currentBlockHeight, double transferAmount) {
    int forkMilestoneHeight = 335036;
    
    // Rule 1: Enforce the Master Snapshot Lock (Reject movement if height is below fork milestone)
    if (txSourceBlockHeight < forkMilestoneHeight) {
        std::cout << "[CONVERGENCE REJECTION] Transaction source block #" << txSourceBlockHeight 
                  << " is locked inside the Master Snapshot Holding Vault.\n";
        std::cout << "[GOVERNANCE] Asset movement restricted until SHARE_FTG Referendum achieves absolute consensus.\n";
        return false;
    }
    
    // Rule 2: Enforce Linear Vesting Escrow for newly unlocked post-fork blocks
    int blocksMinedSinceFork = currentBlockHeight - forkMilestoneHeight;
    if (blocksMinedSinceFork < 100) {
        std::cout << "[VESTING RESTRICTION] Node is inside a slow-release vesting velocity curve.\n";
        return false;
    }
    
    return true;
}
