#include <iostream>
#include <string>
#include <map>

class QmaskGovernanceEngine {
private:
    const std::string founderAddress = "qmpFounderVaultAddress_YOSHIKI_MASTER_KEY";
    double vestedQuarantineBalance = 1000.00; // Starting sample tokens inside the holding chamber

public:
    // 🛡️ 1. WALLET COMPLIANCE AUDITOR: Evaluates peer behavior and applies dynamic penalties
    double AuditPeerCompliance(const std::string& minerAddress, double originalReward, int infractionSeverity) {
        if (infractionSeverity == 0) {
            std::cout << "🟢 [Compliance] Miner " << minerAddress.substr(0, 15) << "... behaves perfectly. Full reward issued.\n";
            return originalReward;
        } 
        
        if (infractionSeverity == 1) {
            // Minor infraction: Apply a 20% penalty fee, routing it directly to the Founder Vault
            double penaltyCut = originalReward * 0.20;
            std::cout << "⚠️  [Compliance Warning] Minor infraction logged! 20% penalty redirected to Founder Vault.\n";
            std::cout << "👑 [Founder Transfer] Redirected: " << penaltyCut << " QMK to " << founderAddress.substr(0, 15) << "...\n";
            return originalReward - penaltyCut;
        }

        // Critical infraction (Major attack / Double-spend signature caught)
        // Seize 100% of the block reward instantly and send it straight to the Founder Vault
        std::cout << "🚨 [CRITICAL INFRACTION] Malicious behavior confirmed! Seizing 100% of block rewards.\n";
        std::cout << "👑 [Founder Transfer] Seized: " << originalReward << " QMK routed to Founder Vault for network defense.\n";
        return 0.0;
    }

    // ⏳ 2. VESTED QUARANTINE MATRIX: Determines if holding coins burn or route to the founder
    void ProcessVestedQuarantine(int blocksSinceLastInfraction) {
        std::cout << "⏳ [Quarantine Window] Blocks since last network infraction: " << blocksSinceLastInfraction << "\n";
        
        if (blocksSinceLastInfraction >= 100) {
            // Compliance era achieved: Move all holding tokens to the absolute permanent burn address
            std::cout << "🔥 [Deflation Release] 100-block safety window met! Burning " << vestedQuarantineBalance << " QMK permanently.\n";
            vestedQuarantineBalance = 0.0;
        } else {
            // Network is under active stress: Redirect 50% of the quarantine pool to the founder to fund defense operations
            double emergencyRedirect = vestedQuarantineBalance * 0.50;
            vestedQuarantineBalance -= emergencyRedirect;
            std::cout << "🚨 [Emergency Override] Active infractions recorded! Redirecting " << emergencyRedirect 
                      << " QMK from quarantine holding pool directly to Founder Vault.\n";
        }
        std::cout << "📊 Remaining Quarantine Pool Balance: " << vestedQuarantineBalance << " QMK\n";
        std::cout << "----------------------------------------------------------------\n\n";
    }
};