#include <iostream>

class QmaskChameleonFilter {
public:
    // 🛡️ FUNCTION: Evaluates block times to instantly scale up difficulty against hardware spikes
    double EvaluateAsymmetricDifficulty(double currentBaselineDifficulty, long long measuredBlockTimeSeconds) {
        if (measuredBlockTimeSeconds < 2) {
            // Flash-attack signature detected! Instantly scale difficulty up by 5x for this block to freeze the farm out
            std::cout << "🚨 [Chameleon Alert] Hostile Hash Array detected! Block solved in: " << measuredBlockTimeSeconds << "s\n";
            return currentBaselineDifficulty * 5.0;
        }
        
        // Return standard difficulty if block rhythm is normal
        return currentBaselineDifficulty;
    }
};
