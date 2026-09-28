#include <iostream>
#include <string>
#include <cstdint>

class QmaskReverseHarmonicEngine {
private:
    const uint64_t BLOCKS_PER_YEAR = 3153600; // 10-second block generation rhythm

public:
    // 🔀 THE REVERSE WAVE: 8-Year lifecycle tracking a gradual build followed by a rapid crash
    double CalculateReverseEmission(uint64_t currentBlockHeight) {
        uint64_t currentEpochBlock = currentBlockHeight % (8 * BLOCKS_PER_YEAR);
        uint64_t activeYear = currentEpochBlock / BLOCKS_PER_YEAR;

        std::cout << "🔀 [Harmonic Engine 2] Active Block Height: #" << currentBlockHeight 
                  << " | Reverse Cycle Year: [" << activeYear << "]\n";

        // --- PHASE 1: THE REVERSE GRADUAL INFLATION BUILD (Years 0 to 4) ---
        if (activeYear < 4) {
            std::cout << "🌋 [REVERSE VOLCANIC BUILD] Inflation expanding gradually in reverse format...\n";
            double floorReward = 0.50;
            double peakReward = 4.00;
            uint64_t totalPhaseBlocks = 4 * BLOCKS_PER_YEAR;

            double dynamicBuild = floorReward + 
                ((peakReward - floorReward) * (static_cast<double>(currentEpochBlock) / totalPhaseBlocks));

            std::cout << "📈 Reverse Loop Action: Slowly scaling up block reward to [" << dynamicBuild << " QMK]\n";
            return dynamicBuild;
        }

        // --- PHASE 2: THE REVERSE RAPID CRASHING WAVE (Years 4 to 8) ---
        std::cout << "🌊 [REVERSE CRASHING WAVE] Initiating rapid supply compression loop...\n";
        uint64_t phase2StartBlock = 4 * BLOCKS_PER_YEAR;
        uint64_t elapsedInPhase = currentEpochBlock - phase2StartBlock;
        uint64_t totalPhaseBlocks = 4 * BLOCKS_PER_YEAR;

        double maxReward = 4.00;
        double minReward = 0.10;

        double dynamicCrash = maxReward - 
            ((maxReward - minReward) * (static_cast<double>(elapsedInPhase) / totalPhaseBlocks));

        std::cout << "🔥 Reverse Loop Action: Crashing block emission down to [" << dynamicCrash << " QMK]\n";
        return dynamicCrash;
    }
};

