#ifndef QMASK_SUBSIDY_H
#define QMASK_SUBSIDY_H

class QmaskSubsidyEngine {
private:
    // ⚙️ Hardcoding the economic parameters matching the 15-second block target
    const int halvingIntervalBlocks = 2102400; // 2,102,400 blocks = exactly 365 days
    const double initialBlockReward = 25.00;   // Launch reward baseline per block

public:
    // 🪙 Calculates the exact newly-minted token reward amount for any block height
    double GetCurrentBlockReward(int currentBlockHeight);
};

#endif // QMASK_SUBSIDY_H
