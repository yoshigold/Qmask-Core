#include <iostream>
#include <cmath>
#include <iomanip>

class QmaskEconomicsEngine {
private:
    const double baseBlockSizeLimit = 1000000.0; // 1 MB base block size limit baseline
    const double maxTailEmissionCap = 0.50;      // Maximum safety tail emission limit per block (in QMK)

public:
    // 🐋 1. DYNAMIC BLOCK SIZE CONTROLLER (Monero-style bounded scaling)
    double CalculateDynamicBlockSizeLimit(double historicalMedianSize) {
        // Allow the block capacity to scale up to 2x the recent historical median size
        double calculatedLimit = historicalMedianSize * 2.0;
        
        // Enforce the base baseline minimum so the block size cannot shrink below standard levels
        if (calculatedLimit < baseBlockSizeLimit) {
            return baseBlockSizeLimit;
        }
        return calculatedLimit;
    }

    // ⛏️ 2. LOYALTY RESERVE POOL (Difficulty-Inverted Adaptive Tail Emission)
    double CalculateAdaptiveTailEmission(double currentNetworkHashrate) {
        // Baseline low network hashrate anchor (representing 1-10 home nodes mining competitively)
        double lowHashrateAnchor = 1000.0; 

        if (currentNetworkHashrate <= lowHashrateAnchor) {
            // Low competition era: Release maximum loyalty rewards to keep home miners profitable
            return maxTailEmissionCap;
        }

        // High competition era: Apply an inverse scaling curve. 
        // As hashrate increases, inflation decreases to protect coin scarcity.
        double emissionReductionFactor = lowHashrateAnchor / currentNetworkHashrate;
        double dynamicEmission = maxTailEmissionCap * emissionReductionFactor;

        // Hard baseline floor: Ensure inflation never drops below 0.0
        if (dynamicEmission < 0.0) dynamicEmission = 0.0;
        return dynamicEmission;
    }
};