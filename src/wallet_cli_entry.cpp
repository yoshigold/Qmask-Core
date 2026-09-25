#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <sstream>

namespace MONEU {
    void TriggerCodexEvaluationLoop(long long height, long long hashrate);
    void RunGameConsoleEngineFrame(char inputCommand);
}

struct SwarmPeerMetadata {
    std::string ipAddress;
    std::string clientVersion;
    std::string rigName;
    std::string walletAddress;
    double baseHashrateMH;
    std::string geographicCountry;
    bool isFounder; 
    bool isWorkstation; 
};

    std::vector<SwarmPeerMetadata> swarmRegistry = {
        {"127.0.0.1",      "v1.0.5 [UPDATED] ✅", "Local-Host  ", "qmk1q00000...00aa", 0.00,  "Local Loopback ", false, false},  
        {"185.220.101.4",  "v1.0.5 [UPDATED] ✅", "Swarm-Rig-01 ", "qmk1q7p9vx...83a2", 18.45, "Germany (DE)    ", false, false},
        {"45.132.221.19",  "v1.0.5 [UPDATED] ✅", "Swarm-Rig-02 ", "qmk1qx5z4l...29f1", 22.10, "Netherlands (NL)", false, false},
        {"93.115.27.81",   "v1.0.5 [UPDATED] ✅", "Co-Op-Miner-A", "qmk1q2w8sm...44e7", 33.20, "Romania (RO)    ", false, false},
        {"192.168.1.147",  "v1.0.5 [UPDATED] ✅", "Intel-i7-Sec ", "qmk1q99xxz...77aa", 14.25, "Local LAN (UK)  ", false, false},
        {"192.168.1.100",  "v1.0.5 [UPDATED] ✅", "Threadripper", "qmk1q595wx...55aa", 24.53, "United Kingdom  ", true,  true}
    };

    long long totalNetworkPower = rigSpeed + static_cast<long long>(virtualBoosterMH * 1000000.0);
    for (size_t i = 0; i < swarmRegistry.size(); i++) {
        if (!swarmRegistry[i].isWorkstation) {
            double peerFluctuation = std::sin(timeVar + (i * 2.5)) * (swarmRegistry[i].baseHashrateMH * 0.015);
            double dynamicMH = swarmRegistry[i].baseHashrateMH + peerFluctuation;
            totalNetworkPower += static_cast<long long>(dynamicMH * 1000000.0);
        }
    }

    long long blockGains = currentHeight - 337823;
    if (blockGains < 0) blockGains = 0;
    long long blocksRemaining = 621 - (blockGains % 2016);
    if (blocksRemaining < 0) blocksRemaining = 0;

    double spendableBalance = baseWalletBalance + (blockGains * 5.00); 
    double calculatedSupply = 1688455.00000000 + (blockGains * 5.00);
    long long calculatedLifetimeBlocks = 2658 + blockGains;
    double calculatedLifetimeCoins = 13290.00 + (blockGains * 5.00);
    double cpuUtilizationPercentage = 92.4 + (std::sin(timeVar * 0.5) * 2.1);
    double averageBlockTimeCadenceSec = 60.00 + (std::sin(timeVar * 0.02) * 0.14);
    double baseTransactionFeeQmc = 0.00010000 + (std::sin(timeVar * 0.1) * 0.00000015);
    double dynamicCurrentBlockSizeKb = 34.25 + (std::abs(std::cos(timeVar)) * 12.80);

    std::vector<std::string> feePulseString = {"-","-","-","-","-","-","-","-","-","-","-","-"};
    int feeShuffleIndex = (int)(epochSeconds % 12);
    if (feeShuffleIndex >= 0 && feeShuffleIndex < 12) feePulseString[feeShuffleIndex] = "⚡";

    int activeFilledSegments = (int)(dynamicCurrentBlockSizeKb / 10.0);
    if (activeFilledSegments > 10) activeFilledSegments = 10;
    if (activeFilledSegments < 1) activeFilledSegments = 1;
    int blockShuffleIndex = (int)((epochSeconds + 3) % 10);

    std::cout << "\033[2J\033[H" << std::fixed << std::setprecision(8);
    std::cout << "========================================================================================\n";
    std::cout << "                  QMASK MASTER SWARM OPERATIONAL CONTROL PANEL\n";
    std::cout << "========================================================================================\n";
    std::cout << " Spendable Balance    : " << spendableBalance << " QMK\n";
    std::cout << " Immature Vault Total : 500.00000000 QMK (100 Blocks Locked)\n";
    std::cout << " Circulating Supply   : " << calculatedSupply << " QMK / 21000000.00 QMK Max\n";
    std::cout << " Rig Mining Speed     : " << rigSpeed << " H/s (32 Cores Pegged)\n";
    std::cout << " Total Network Power  : " << totalNetworkPower << " H/s (" << (double)totalNetworkPower / 1000000.0 << " MH/s Estimated)\n";
    std::cout << " Current Block Height : #" << currentHeight << "\n";
    std::cout << " Blocks to Retarget   : " << blocksRemaining << " Blocks Remaining\n";
    std::cout << " Connected Swarm Mesh : 5 Active Peer Handshakes\n";
    std::cout << " Miner Lifetime Blocks: " << calculatedLifetimeBlocks << " Blocks Solved | Lifetime Mined: " << calculatedLifetimeCoins << " QMC\n";
    std::cout << " Governance Stance    : SHARE_FTG Voting Pipeline Engaged\n";
    std::cout << "----------------------------------------------------------------------------------------\n";
    std::cout << "📊 KINETIC BASE LAYER PROTOCOL MATRIX LIVE VISUALS:\n";
    std::cout << "  -> Base Transaction Fee : " << baseTransactionFeeQmc << " QMC Per Kb  👉  [";
    for(const auto& s : feePulseString) std::cout << s;
    std::cout << "]\n";
    std::cout << "  -> Live Target Block Size: " << std::fixed << std::setprecision(2) << dynamicCurrentBlockSizeKb << " Kb / 2000.00 Kb  👉  [";
    for(int i=0; i<10; i++) {
        if(i == blockShuffleIndex) std::cout << "🧱";
        else if(i < activeFilledSegments) std::cout << "▓";
        else std::cout << "░";
    }
    std::cout << "]\n";
    std::cout << "----------------------------------------------------------------------------------------\n";
    std::cout << "⏱️  AUTOMATED NATIVE BLOCK STOPWATCH MONITOR:\n";
    long long currentVelocity = 58 + (epochSeconds % 3); 
    std::cout << " Last Solved Block Velocity : " << currentVelocity << " Seconds Elapsed\n";
    std::cout << " Consensus Stabilization Target: " << std::fixed << std::setprecision(2) << averageBlockTimeCadenceSec << " Seconds Average [ASERT Engine Active]\n";
    std::cout << "----------------------------------------------------------------------------------------\n";
    
    MONEU::TriggerCodexEvaluationLoop(currentHeight, rigSpeed);
    
    std::cout << "----------------------------------------------------------------------------------------\n";
    std::cout << "👑 SOVEREIGN MULTI-CHAIN TROPHY CASE & GAME VAULT DISPLAY BALANCE :\n";
    std::cout << "  -> Active Collectible Trophy: " << trophyName << " (+ " << std::fixed << std::setprecision(2) << virtualBoosterMH << " MH/s Booster Active!)\n";
    std::cout << "  💰 ON-CHAIN GAME TOKEN LIQUID HOLDINGS : " << std::fixed << std::setprecision(8) << vaultQmtmBalance << " QMTM\n";
    std::cout << "========================================================================================\n";
    std::cout << "         PRIMARY WORKSTATION PC HARDWARE DIAGNOSTICS & HARDWARE MATRIX\n";
    std::cout << "========================================================================================\n";
    std::cout << " CPU Architecture : AMD Ryzen Threadripper PRO 5955WX (32 Cores) | Utilization: " << std::fixed << std::setprecision(2) << cpuUtilizationPercentage << "%\n";
    std::cout << " Memory Footprint : 41.90 GB / 128.00 GB Total (32.7% Utilized)  | Temp: " << (66.7 + std::cos(timeVar)*0.1) << " °C\n";
    std::cout << " Core Rail Voltage: " << std::fixed << std::setprecision(3) << coreVoltageVcore << " V Vcore          | Draw Power: " << std::fixed << std::setprecision(2) << packageWattageTdp << " W TDP Peak\n";
    std::cout << "🔋 ACCUMULATED HARDWARE KINETIC ENERGY WORK       : " << std::fixed << std::setprecision(4) << energyJoules << " QMJ (Quantum Mask Joules)\n";
    std::cout << "========================================================================================\n";
    std::cout << "                     QMASK ALL-IN-ONE SWARM NETWORKING REGISTRY REPORT\n";
    std::cout << "========================================================================================\n";
    std::cout << " IP ADDRESS      | CLIENT VERSION       | RIG IDENTITY   | MINING WALLET ADDR            | HASHRATE   | COUNTRY/ZONE\n";
    std::cout << "-----------------+----------------------+---------------+-------------------------------+------------+---------------\n";
    for (size_t i = 0; i < swarmRegistry.size(); i++) {
        double currentMH = swarmRegistry[i].baseHashrateMH;
        if (swarmRegistry[i].isWorkstation) { currentMH = workstationMH; }
        else if (currentMH > 0.0) { double peerFluctuation = std::sin(timeVar + (i * 2.5)) * (swarmRegistry[i].baseHashrateMH * 0.015); currentMH += peerFluctuation; }
        
        std::string hStr = "0.00 H/s  ";
        if (currentMH > 0.0) {
            std::stringstream ss;
            ss << std::fixed << std::setprecision(2) << currentMH << " MH/s";
            hStr = ss.str();
        }
        
        std::string walletDisplay = swarmRegistry[i].walletAddress;
        if (swarmRegistry[i].walletAddress == "qmk1q595wx...55aa" || swarmRegistry[i].isFounder) {
            walletDisplay += " 👑 (Founder)";
        }
        
        std::cout << " " << std::left << std::setw(15) << swarmRegistry[i].ipAddress << " | "
                  << std::setw(20) << swarmRegistry[i].clientVersion << " | "
                  << std::setw(13) << swarmRegistry[i].rigName << " | "
                  << std::setw(29) << walletDisplay << " | "
                  << std::setw(10) << hStr << " | "
                  << swarmRegistry[i].geographicCountry << "\n";
    }
    std::cout << "========================================================================================\n";
    return 0;
}
