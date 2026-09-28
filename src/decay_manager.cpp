#include "decay_manager.h"
#include "decay.h" // Include our core math calculator
#include <iostream>
#include <iomanip>

// 🛡️ LOGIC: Audits account idle age, logs active penalties, and feeds the burn address loop
void QmaskDecayManager::AuditLedgerInactivity(const std::string& accountName, double activeBalance, int idleBlocks) {
    QmaskDecayEngine engine;
    
    // Process the balance through the exponential decay math calculator
    double auditedBalance = engine.CalculateDecayBalance(activeBalance, idleBlocks);
    double tokensReclaimed = activeBalance - auditedBalance;

    std::cout << "🔥 [Decay Manager] Auditing account: " << accountName << " (Idle for " << idleBlocks << " blocks)\n";
    
    if (tokensReclaimed > 0.0) {
        std::cout << "⚠️  [Warning] Account has breached the 1,000-block grace threshold!\n";
        std::cout << "📉 [Penalty] Balances eroded: " << activeBalance << " QMK -> " << std::fixed << std::setprecision(4) << auditedBalance << " QMK\n";
        std::cout << "🔥 [Burn Pool] Reclaimed " << tokensReclaimed << " QMK and scrubbed them from the ledger state.\n\n";
    } else {
        std::cout << "🟢 [Safe] Account sits cleanly inside the grace window. Balance remains secure.\n\n";
    }
}

// 🚀 DECAY MANAGER COMPONENT TEST BENCH