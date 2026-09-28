#include "fees.h"
#include <iostream>
#include <iomanip>

// 🪙 FEES DISTRIBUTION ENGINE CODE LOGIC
void QmaskFeeManager::DistributeFees(double totalBlockFees) {
    double minerPayout = totalBlockFees * minerRewardShare;
    double burnAmount = totalBlockFees * deflationaryBurnShare;

    std::cout << "================================================================\n";
    std::cout << "🪙 TRANSACTION FEE CALCULATIONS FOR NEW LEDGER BLOCK\n";
    std::cout << "================================================================\n";
    std::cout << "💳 Total Fees Collected in Block: " << totalBlockFees << " QMK\n";
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "⛏️  Miner Allocation (60%)     : " << std::fixed << std::setprecision(4) << minerPayout << " QMK (Liquid payout)\n";
    std::cout << "🔥 Deflationary Burn (40%)    : " << std::fixed << std::setprecision(4) << burnAmount << " QMK (Permanently destroyed)\n";
    std::cout << "================================================================\n";
    std::cout << "✨ Deflation loop executed. Token scarcity increased safely.\n\n";
}

// 🚀 ECONOMIC SYSTEM TEST BENCH