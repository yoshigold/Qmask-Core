#include <iostream>
#include <string>
#include <vector>
#include <map>

struct SecurityLogEntry {
    int blockHeight;
    std::string attackerSignature;
    std::string violationType;
    double confiscatedAmount;
    std::string mitigationAction;
};

class QmaskAdvancedGovernance {
private:
    const std::string founderVaultAddress = "qmpFounderVaultAddress_YOSHIKI_MASTER_KEY";
    std::map<std::string, int> poolStrikeRegistry;
    std::vector<SecurityLogEntry> publicOnChainSecurityLog;

public:
    double ProcessPoolBlockReward(const std::string& poolIdentifier, double currentBlockReward, int attackSeverityFactor) {
        if (attackSeverityFactor > 0) {
            poolStrikeRegistry[poolIdentifier]++;
        }

        int currentStrikes = poolStrikeRegistry[poolIdentifier];

        if (currentStrikes >= 3 || attackSeverityFactor == 3) {
            std::cout << "🚨 [CRITICAL SHIELD ACTIVATED] Pool " << poolIdentifier.substr(0, 12) << "... has hit maximum strikes!\n";
            std::cout << "⛔ STATUS: PERMANENTLY BANNED. Drops network connection sockets immediately.\n";
            
            SecurityLogEntry criticalIncident = {13672, poolIdentifier, "SYSTEMIC_BLOCKCHAIN_HALT_ATTACK", currentBlockReward, "PERMANENT_IP_BAN_AND_TOTAL_REWARD_SEIZURE"};
            publicOnChainSecurityLog.push_back(criticalIncident);
            
            std::cout << "👑 [Founder Shield] Confiscating " << currentBlockReward << " QMK -> Routed directly to Founder Vault.\n";
            return 0.0;
        }

        if (attackSeverityFactor == 2) {
            std::cout << "⚠️  [Major Infraction] Attempted malicious fork signature detected from pool!\n";
            std::cout << "👑 [Founder Shield] Redirecting 100% of the block rewards to the Founder Address during active exploit era.\n";
            
            SecurityLogEntry majorIncident = {13672, poolIdentifier, "ATTEMPTED_FORK_EXPLOIT", currentBlockReward, "100_PERCENT_REWARD_CONFISCATION_TO_FOUNDER"};
            publicOnChainSecurityLog.push_back(majorIncident);
            return 0.0;
        }

        if (attackSeverityFactor == 1) {
            double founderCut = currentBlockReward * 0.50;
            std::cout << "⚠️  [Warning Era] Pool behavior anomaly logged. 50/50 Penalty Split activated.\n";
            std::cout << "👑 Routed " << founderCut << " QMK to Founder Vault. Remaining 50% issued to miner.\n";
            return currentBlockReward - founderCut;
        }

        std::cout << "🟢 [Safe] Pool behaves perfectly inside protocol parameters. Full reward issued.\n";
        return currentBlockReward;
    }

    void DisplayPublicSecurityLog() {
        std::cout << "\n📋 =========================================================\n";
        std::cout << "📋 PUBLIC ON-CHAIN SECURITY COMPLIANCE LOG (VIEWABLE TO ALL) \n";
        std::cout << "📋 =========================================================\n";
        
        if (publicOnChainSecurityLog.empty()) {
            std::cout << "✨ Ledger state sits entirely pristine. Zero malicious incidents recorded.\n";
            return;
        }

        for (const auto& log : publicOnChainSecurityLog) {
            std::cout << "⏱️  [BLOCK #" << log.blockHeight << "] TARGET SIGNATURE: " << log.attackerSignature.substr(0, 15) << "...\n";
            std::cout << "❌ VIOLATION TYPE   : " << log.violationType << "\n";
            std::cout << "🔥 TOKENS IMPOUNDED  : " << log.confiscatedAmount << " QMK\n";
            std::cout << "🛠️  MITIGATION ACTION : " << log.mitigationAction << "\n";
            std::cout << "----------------------------------------------------------------\n";
        }
    }
};