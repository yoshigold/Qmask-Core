#ifndef QMASK_DIFFICULTY_H
#define QMASK_DIFFICULTY_H

class QmaskDifficultyRegulator {
private:
    // ⚙️ Hardcoding our block spacing safety targets
    const int targetBlockTime = 15; // Target exactly 15 seconds per block
    const double halfLife = 3600.0; // 1-hour half-life speed for adjustment response scaling

public:
    // 🎛️ Dynamically calculates the next block's precise numeric difficulty factor
    double CalculateNextDifficulty(double currentDifficulty, long long timeSinceLastBlock);
};

#endif // QMASK_DIFFICULTY_H
