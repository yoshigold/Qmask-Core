#include <iostream>
#include <string>
#include <cstdint>
#include <cmath>

class QmaskVolcanicWaveEngine {
private:
    const uint64_t BLOCKS_PER_YEAR = 3153600; // 10-second block generation rhythm
    double totalCirculatingPool = 258375675.0;

public:
    // 🌋 THE MACRO OSCILLATOR: Automatically applies Crashing Wave burns and Volcanic builds
    double CalculateVolcanicEmission(uint64_t currentBlockHeight) {
        uint64_t currentEpochBlock = currentBlockHeight % (16 * BLOCKS_PER_YEAR);
        uint64_t activeYear = currentEpochBlock / BLOCKS_PER_YEAR;

        std::cout << "🪐 [STVW Engine] Active Block Height: #" << currentBlockHeight 
                  << " | Epoch Lifecycle Year: [" << activeYear << "]\n";

        // --- CYCLE WAVE 1: THE CRASHING WAVE CONTRACTOR ---
        if (activeYear >= 4 && activeYear < 8) {
            std::cout << "🌊 [CRASHING WAVE ACTIVE] Executing macro-supply automated contraction loop...\n";
            // Progressively track the 255,750,675 QMK structural on-chain burn
            double totalBurnTarget = 255750675.0;
            uint64_t waveDurationBlocks = 4 * BLOCKS_PER_YEAR;
            double burnPerBlock = totalBurnTarget / waveDurationBlocks;

            std::cout << "🔥 System Action: Vaporizing [" << burnPerBlock << " QMK] straight out of this block's parameters.\n";
            return 0.10; // Clamp the active mining payout down to a minimal floor during the burn phase
        }

        // --- CYCLE WAVE 2: THE VOLCANIC ERUPTION BUILDER ---
        if (activeYear >= 8 && activeYear < 16) {
            std::cout << "🌋 [VOLCANIC ERUPTION ACTIVE] Gradual build-up of tail emission layer running...\n";
            uint64_t phase2StartBlock = 8 * BLOCKS_PER_YEAR;
            uint64_t elapsedBlocksInPhase = currentEpochBlock - phase2StartBlock;

            // Mathematical slope: Gradually increment block rewards over the 8-year volcanic timeline
            double baselineFloorReward = 0.50; 
            double maximumEruptionReward = 5.00;
            uint64_t totalPhaseBlocks = 8 * BLOCKS_PER_YEAR;

            double dynamicRewardChange = baselineFloorReward + 
                ((maximumEruptionReward - baselineFloorReward) * (static_cast<double>(elapsedBlocksInPhase) / totalPhaseBlocks));

            std::cout << "✨ Smooth Inflation Log: Block Reward gradually expanding to [" << dynamicRewardChange << " QMK]\n";
            return dynamicRewardChange;
        }

        // Standard operational mining baseline layout (Years 0 to 4)
        std::cout << "🟢 Stable Baseline Loop: Issuing regular 5.00 QMK mining reward blocks.\n";
        return 5.00;
    }
};

