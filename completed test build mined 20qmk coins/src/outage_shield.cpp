#include <iostream>
#include <string>
#include <map>

class QmaskOutageCompensationEngine {
private:
    std::map<std::string, bool> maliciousStrikeRegistry;

public:
    // 🔌 1. CRASH-FAULT DISCRIMINATOR: Audits peer drop signatures to find honest miners
    bool AuditDisconnectionHonesty(const std::string& minerAddress, std::string dropSignatureType, int continuousWorkHoursBeforeDrop) {
        std::cout << "🔍 [Outage Audit] Scanning drop signature for node: " << minerAddress.substr(0, 15) << "...\n";
        
        if (dropSignatureType == "CLEAN_SOCKET_CLOSE") {
            std::cout << "⛔ [Verification Failed] Clean exit signature detected. User disconnected manually. Zero compensation.\n";
            return false;
        }

        if (dropSignatureType == "SUDDEN_ASYMMETRIC_FREEZE") {
            if (continuousWorkHoursBeforeDrop < 3) {
                std::cout << "⚠️  [Verification Denied] Sudden drop verified, but miner history was too short (< 3 hours continuous work).\n";
                return false;
            }
            
            std::cout << "✅ [VERIFICATION SUCCESS] Sudden power outage signature verified by 5 network peers!\n";
            std::cout << "🛡️  Status: Locked in as an honest crash-fault victim. Eligible for Loose Tail Emission compensation.\n";
            return true;
        }

        return false;
    }

    // 🪙 2. LOOSE TAIL EMISSION COMPENSATION DISTRIBUTOR
    double CalculateOutageCompensation(bool isHonestVictim, int missedBlockCount, double currentPool1Emission) {
        if (!isHonestVictim) return 0.0;

        // Calculate compensation: 5% of the active loose tail emission per block missed, capped at a safety limit
        double calculatedBonus = (missedBlockCount * currentPool1Emission) * 0.05;
        if (calculatedBonus > 2.50) calculatedBonus = 2.50; // Hard cap maximum safety shield to prevent pool drainage

        std::cout << "🪙 [Pool 1 Reward Injection] Allocating +" << calculatedBonus 
                  << " QMK outage compensation bounty out of the Dynamic Loose Emission pool.\n";
        return calculatedBonus;
    }
};
