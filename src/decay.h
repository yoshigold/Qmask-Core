#ifndef QMASK_DECAY_H
#define QMASK_DECAY_H

class QmaskDecayEngine {
private:
    // ⚙️ Setting the inactivity thresholds for your coin
    const int decayGracePeriodBlocks = 1000; // Wallet balance is safe for 1,000 blocks of idle time
    const double decayRatePerBlock = 0.0005; // 0.05% compounding decay rate per block past threshold

public:
    // 🔥 Calculates the remaining wallet balance dynamically based on block inactivity time
    double CalculateDecayBalance(double originalBalance, int blocksSinceLastActive);
};

#endif // QMASK_DECAY_H
