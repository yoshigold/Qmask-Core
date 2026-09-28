#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

class QmaskMirrorSuccessEngine {
private:
    const double highHashrateThresholdMhs = 500000.00; // 500,000 MH/s defines our adoption explosion spike
    double basePool1EmissionQmk = 5.00;                // Pool 1 starts at its standard 5.00 QMK baseline

public:
    // 📊 1. MAGI-INSPIRED REWARD CHOKE VALVE: Insulates token scarcity during hardware surges
    double EvaluateNetworkGrowthAndChokeRewards(double liveParentHashrateMhs) {
        std::cout << "📡 [Telemetry Link] Scanning current parent chain global hashrate: " << liveParentHashrateMhs << " MH/s\n";

        if (liveParentHashrateMhs >= highHashrateThresholdMhs) {
            // Success Spike Caught: Choke rewards down to shield against industrial inflation dumps
            double chokeFactor = 1.0 + (liveParentHashrateMhs / highHashrateThresholdMhs);
            double adjustedEmission = basePool1EmissionQmk / chokeFactor;
            
            if (adjustedEmission < 1.00) adjustedEmission = 1.00; // Enforce a firm 1.00 QMK floor boundary

            std::cout << "🛡️  [REWARD CHOKE VALVE ACTIVE] Moneu has entered an exponential success surge!\n";
            std::cout << "📉 Action: Compressing Pool 1 Loose Emission from " << basePool1EmissionQmk 
                      << " down to " << std::fixed << std::setprecision(4) << adjustedEmission << " QMK per block.\n";
            return adjustedEmission;
        }

        std::cout << "⚖️  System Normal: Parent hashrate sits within baseline home mining boundaries.\n";
        return basePool1EmissionQmk;
    }

    // 🎮 2. GAMEPLAY SUCCESS CATALYST TRIGGER: Activates in-game rewards on Mirror 0
    void TriggerEcosystemSuccessMultipliers(double liveParentHashrateMhs) {
        if (liveParentHashrateMhs >= highHashrateThresholdMhs) {
            std::cout << "🎮 [Qmask Tactics Event] Global Success Season Event UNLOCKED inside Mirror 0!\n";
            std::cout << "✨ Game Logic: Proof-of-Work creature capsule spawn rates multiplied by [2x] across all maps!\n";
            std::cout << "👑 Status: High-Tier QSR Staking vaults are fully operational to absorb incoming liquidity velocity.\n";
        } else {
            std::cout << "🎮 Game Logic: Standard exploration rates active. No global season events triggered yet.\n";
        }
        std::cout << "----------------------------------------------------------------\n\n";
    }
};

int main() {
    std::cout << "🚀 =========================================================\n";
    std::cout << "🚀 INITIALIZING ALPHA-0 MIRROR 0 SUCCESS-SCALE CORE ENGINE  \n";
    std::cout << "🚀 =========================================================\n\n";

    QmaskMirrorSuccessEngine successEngine;

    // CASE A: Parent chain is running at standard baseline home network metrics
    successEngine.EvaluateNetworkGrowthAndChokeRewards(12000.00);
    successEngine.TriggerEcosystemSuccessMultipliers(12000.00);

    // CASE B: Parent chain hasrate explodes by 6x past our target threshold
    successEngine.EvaluateNetworkGrowthAndChokeRewards(3000000.00);
    successEngine.TriggerEcosystemSuccessMultipliers(3000000.00);

    return 0;
}
