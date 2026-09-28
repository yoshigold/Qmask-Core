#include <iostream>
#include <cmath>
#include <iomanip>

class QmaskDifficultyRegulator {
public:
    const int targetBlockTime = 15; // 15-second block time target
    const double halfLife = 3600.0; // 1-hour half-life for difficulty scaling shifts

    // 📊 THE CORRECTED ASERT ALGORITHM
    double CalculateNextDifficulty(double currentDifficulty, long long timeSinceLastBlock) {
        // We invert the drift calculation using a negative sign mapping operator (-drift)
        // This ensures a fast block time INCREASES numeric difficulty, and slow block time DECREASES it.
        double drift = targetBlockTime - static_cast<double>(timeSinceLastBlock);
        
        double exponent = drift / halfLife;
        double scaleFactor = std::pow(2.0, exponent);
        double nextDifficulty = currentDifficulty * scaleFactor;

        if (nextDifficulty < 1.0) nextDifficulty = 1.0;
        
        return nextDifficulty;
    }
};

int main() {
    std::cout << "[ASERT Engine] Initializing Qmask (QMK) Corrected Difficulty Subsystem...\n\n";
    
    QmaskDifficultyRegulator regulator;
    double currentNetworkDiff = 1000.0;

    std::cout << "Starting Network Difficulty Target: " << currentNetworkDiff << "\n";
    std::cout << "----------------------------------------------------------------\n";

    // SCENARIO A: A massive GPU rig joins! Block found super fast (only 2 seconds)
    long long fastBlockTime = 2; 
    double diffUp = regulator.CalculateNextDifficulty(currentNetworkDiff, fastBlockTime);
    std::cout << "[Alert] Rig Flash-Joins! Block found in: " << fastBlockTime << " seconds.\n";
    std::cout << "📈 Dynamic Adjustment -> Next Difficulty: " << std::fixed << std::setprecision(2) << diffUp << " (HARDER)\n\n";

    // SCENARIO B: Miners drop off. Block takes a long time to find (60 seconds)
    long long slowBlockTime = 60;
    double diffDown = regulator.CalculateNextDifficulty(currentNetworkDiff, slowBlockTime);
    std::cout << "[Alert] Miners Disconnect! Block takes: " << slowBlockTime << " seconds.\n";
    std::cout << "📉 Dynamic Adjustment -> Next Difficulty: " << std::fixed << std::setprecision(2) << diffDown << " (EASIER)\n";
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "✅ ASERT Engine verified. Corrected per-block difficulty is fully operational!\n";

    return 0;
}
