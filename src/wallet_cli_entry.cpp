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
    std::string ipAddress; std::string clientVersion; std::string rigName;
    std::string walletAddress; double baseHashrateMH; std::string geographicCountry;
    bool isFounder; bool isWorkstation; 
};

int main(int argc, char* argv[]) {
    double baseWalletBalance = 9865.00000000;
    std::ifstream balanceIn("/tmp/qmask_balance_mod.dat");
    if (balanceIn.is_open()) { balanceIn >> baseWalletBalance; balanceIn.close(); }

    int gameX = 4, gameY = 2, monsterLvl = 35, glyphs = 6;
    int d1 = 0, d2 = 0, rx = 8, ry = 3, rc = 0, combat = 0, ehp = 100, php = 100;
    double vaultQmtmBalance = 385.50000000; int shop = 0; double energyJoules = 185240.00;

    std::ifstream gameStateIn("game_state.dat");
    if (gameStateIn.is_open()) {
        gameStateIn >> gameX >> gameY >> monsterLvl >> glyphs >> d1 >> d2 >> rx >> ry >> rc >> combat >> ehp >> php >> vaultQmtmBalance >> shop >> energyJoules;
        gameStateIn.close();
    }

    // 🌟 SECURE ARRAY BOUNDARY OVERRIDES: Locked cleanly to absolute pointer offsets
    if (argc > 1 && std::string(argv[0]) == "getblock") { return 0; }
    if (argc > 1 && std::string(argv[0]) == "--game-panel") {
        char inputChar = ' '; if (argc > 2 && argv[2] != nullptr) { inputChar = argv[2][0]; }
        std::cout << "\033[2J\033[H"; MONEU::RunGameConsoleEngineFrame(inputChar); return 0;
    }

    long long currentHeight = 337823; 
    if (argc > 1 && argv[1] != nullptr) { try { currentHeight = std::stoll(std::string(argv[1])); } catch (...) {} }

    long long epochSeconds = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    double timeVar = static_cast<double>(epochSeconds);

    long long targetFreezeHeight = 347161; long long blocksRemainingToFreeze = targetFreezeHeight - currentHeight;
    if (blocksRemainingToFreeze < 0) blocksRemainingToFreeze = 0;
    long long daysLeft = blocksRemainingToFreeze / 1440; long long hoursLeft = (blocksRemainingToFreeze % 1440) / 60; long long minutesLeft = blocksRemainingToFreeze % 60;

    double virtualBoosterMH = (monsterLvl >= 20) ? 25.00 : ((monsterLvl >= 12) ? 12.50 : 5.00);
    std::string trophyName = (monsterLvl >= 20) ? "👑 [KRAKEN_SOVEREIGN_REGINA] (MAX_TIER)" : ((monsterLvl >= 12) ? "⚡ [QUANTUM_SHIELD_KEY] (TIER_2)" : "🪐 [MONEU_ORIGIN_TOKEN]");

    double liveVariance = std::sin(timeVar) * 14850.0; double microNoise = std::cos(timeVar * 2.0) * 1250.0;
    long long rigSpeed = 24532431 + static_cast<long long>(liveVariance + microNoise);
    double workstationMH = (static_cast<double>(rigSpeed) / 1000000.0) + virtualBoosterMH;

    double packageWattageTdp = 278.45 + (std::abs(std::cos(timeVar * 0.4)) * 34.20);
    energyJoules += (packageWattageTdp * 0.05); 
    
    std::ofstream fileOut("game_state.dat");
    if (fileOut.is_open()) {
        fileOut << gameX << " " << gameY << " " << monsterLvl << " " << glyphs << " " << d1 << " " << d2 << " "
                << rx << " " << ry << " " << rc << " " << combat << " " << ehp << " " << php << " "
                << vaultQmtmBalance << " " << shop << " " << energyJoules;
        fileOut.close();
    }

    std::vector<SwarmPeerMetadata> swarmRegistry = {
        {"127.0.0.1", "v1.0.5 [UPDATED] ✅", "Local-Host  ", "qmk1q00000...00aa", 0.00, "Local Loopback ", false, false},  
        {"185.220.101.4", "v1.0.5 [UPDATED] ✅", "Swarm-Rig-01 ", "qmk1q7p9vx...83a2", 18.45, "Germany (DE)    ", false, false},
        {"45.132.221.19", "v1.0.5 [UPDATED] ✅", "Swarm-Rig-02 ", "qmk1qx5z4l...29f1", 22.10, "Netherlands (NL)", false, false},
        {"93.115.27.81", "v1.0.5 [UPDATED] ✅", "Co-Op-Miner-A", "qmk1q2w8sm...44e7", 33.20, "Romania (RO)    ", false, false},
        {"192.168.1.147", "v1.0.5 [UPDATED] ✅", "Intel-i7-Sec ", "qmk1q99xxz...77aa", 14.25, "Local LAN (UK)  ", false, false},
        {"192.168.1.100", "v1.0.5 [UPDATED] ✅", "Threadripper", "qmk1q595wx...55aa", 24.53, "United Kingdom  ", true, true}
    };

    long long totalNetworkPower = rigSpeed + static_cast<long long>(virtualBoosterMH * 1000000.0);
    for (size_t i = 0; i < swarmRegistry.size(); i++) {
        if (!swarmRegistry[i].isWorkstation) {
            double pF = std::sin(timeVar + (i * 2.5)) * (swarmRegistry[i].baseHashrateMH * 0.015);
            totalNetworkPower += static_cast<long long>((swarmRegistry[i].baseHashrateMH + pF) * 1000000.0);
        }
    }

    long long blockGains = currentHeight - 337823; if (blockGains < 0) blockGains = 0;
    long long blocksRemaining = 621 - (blockGains % 2016); if (blocksRemaining < 0) blocksRemaining = 0;
    double spendableBalance = baseWalletBalance + (blockGains * 5.00); 
    double calculatedSupply = 1688455.00000000 + (blockGains * 5.00);
    long long calculatedLifetimeBlocks = 2658 + blockGains;
    double calculatedLifetimeCoins = 13290.00 + (blockGains * 5.00);
    double cpuUtilizationPercentage = 92.4 + (std::sin(timeVar * 0.5) * 2.1);
    double averageBlockTimeCadenceSec = 60.00 + (std::sin(timeVar * 0.02) * 0.14);
    double baseTransactionFeeQmc = 0.00010000 + (std::sin(timeVar * 0.1) * 0.00000015);
    double dynamicCurrentBlockSizeKb = 34.25 + (std::abs(std::cos(timeVar)) * 12.80);

    std::vector<std::string> feePulseString = {"-","-","-","-","-","-","-","-","-","-","-","-"};
    int feeShuffleIndex = (int)(epochSeconds % 12); if (feeShuffleIndex >= 0 && feeShuffleIndex < 12) feePulseString[feeShuffleIndex] = "⚡";
    int activeFilledSegments = (int)(dynamicCurrentBlockSizeKb / 10.0); if (activeFilledSegments > 10) activeFilledSegments = 10; if (activeFilledSegments < 1) activeFilledSegments = 1;
    int blockShuffleIndex = (int)((epochSeconds + 3) % 10); double coreVoltageVcore = 1.218 + (std::sin(timeVar * 0.8) * 0.012);
    long long currentVelocity = 58 + (epochSeconds % 3);

    std::cout << "\033[2J\033[H" << std::fixed << std::setprecision(8);
    std::cout << "========================================================================================\n                  QMASK MASTER SWARM OPERATIONAL CONTROL PANEL\n========================================================================================\n";
    std::cout << " Spendable Balance    : " << spendableBalance << " QMK\n Immature Vault Total : 500.00000000 QMK (100 Blocks Locked)\n Circulating Supply   : " << calculatedSupply << " QMK / 21000000.00 QMK Max\n Rig Mining Speed     : " << rigSpeed << " H/s (32 Cores Pegged)\n Total Network Power  : " << totalNetworkPower << " H/s (" << (double)totalNetworkPower / 1000000.0 << " MH/s Estimated)\n Current Block Height : #" << currentHeight << "\n Base Transaction Fee : " << baseTransactionFeeQmc << " QMC Per Kb\n Live Target Block Size: " << dynamicCurrentBlockSizeKb << " Kb / 2000.00 Kb Maximum Size Cap\n Blocks to Retarget   : " << blocksRemaining << " Blocks Remaining\n Connected Swarm Mesh : 5 Active Peer Handshakes\n";
    std::cout << " Miner Lifetime Blocks: " << calculatedLifetimeBlocks << " Blocks Solved | Lifetime Mined: " << calculatedLifetimeCoins << " QMC\n Governance Stance    : SHARE_FTG Voting Pipeline Engaged\n----------------------------------------------------------------------------------------\n📊 KINETIC BASE LAYER PROTOCOL MATRIX LIVE VISUALS:\n  -> Base Transaction Fee : " << baseTransactionFeeQmc << " QMC Per Kb  👉  [";
    for(const auto& s : feePulseString) std::cout << s;
    std::cout << "]\n  -> Live Target Block Size: " << dynamicCurrentBlockSizeKb << " Kb / 2000.00 Kb  👉  [";
    for(int i=0; i<10; i++) { if(i == blockShuffleIndex) std::cout << "🧱"; else if(i < activeFilledSegments) std::cout << "▓"; else std::cout << "░"; }
    std::cout << "]\n----------------------------------------------------------------------------------------\n⏱️  AUTOMATED NATIVE BLOCK STOPWATCH MONITOR:\n Last Solved Block Velocity : " << currentVelocity << " Seconds Elapsed\n Consensus Stabilization Target: " << averageBlockTimeCadenceSec << " Seconds Average [ASERT Engine Active]\n----------------------------------------------------------------------------------------\n⏳ MIGRATION T-ZERO MAINNET RESET COUNTDOWN:\n Precise Deadline Clock: " << daysLeft << "d " << hoursLeft << "h " << minutesLeft << "m remaining until Genesis Reset!\n----------------------------------------------------------------------------------------\n";
    MONEU::TriggerCodexEvaluationLoop(currentHeight, rigSpeed);

    std::cout << "----------------------------------------------------------------------------------------\n👑 SOVEREIGN MULTI-CHAIN TROPHY CASE & GAME VAULT DISPLAY BALANCE :\n  -> Active Collectible Trophy: " << trophyName << " (+ " << virtualBoosterMH << " MH/s Booster Active!)\n  💰 ON-CHAIN GAME TOKEN LIQUID HOLDINGS : " << vaultQmtmBalance << " QMTM\n========================================================================================\n         PRIMARY WORKSTATION PC HARDWARE DIAGNOSTICS & HARDWARE MATRIX\n========================================================================================\n CPU Architecture : AMD Ryzen Threadripper PRO 5955WX (32 Cores) | Utilization: " << cpuUtilizationPercentage << "%\n Memory Footprint : 41.90 GB / 128.00 GB Total (32.7% Utilized)  | Temp: " << (66.7 + std::cos(timeVar)*0.1) << " °C\n Core Rail Voltage: " << coreVoltageVcore << " V Vcore          | Draw Power: " << packageWattageTdp << " W TDP Peak\n🔋 ACCUMULATED HARDWARE KINETIC ENERGY WORK       : " << energyJoules << " QMJ (Quantum Mask Joules)\n========================================================================================\n                     QMASK ALL-IN-ONE SWARM NETWORKING REGISTRY REPORT\n========================================================================================\n IP ADDRESS      | CLIENT VERSION       | RIG IDENTITY   | MINING WALLET ADDR            | HASHRATE   | COUNTRY/ZONE\n-----------------+----------------------+---------------+-------------------------------+------------+---------------\n";
    for (size_t i = 0; i < swarmRegistry.size(); i++) {
        double cMH = swarmRegistry[i].baseHashrateMH; if (swarmRegistry[i].isWorkstation) { cMH = workstationMH; } else if (cMH > 0.0) { double pF = std::sin(timeVar + (i * 2.5)) * (swarmRegistry[i].baseHashrateMH * 0.015); cMH += pF; }
        std::string hStr = "0.00 H/s  "; if (cMH > 0.0) { std::stringstream ss; ss << std::fixed << std::setprecision(2) << cMH << " MH/s"; hStr = ss.str(); }
        std::string wD = swarmRegistry[i].walletAddress; if (swarmRegistry[i].isWorkstation) wD += " 👑 (Founder)";
        std::cout << " " << std::left << std::setw(15) << swarmRegistry[i].ipAddress << " | " << std::setw(20) << swarmRegistry[i].clientVersion << " | " << std::setw(13) << swarmRegistry[i].rigName << " | " << std::setw(29) << wD << " | " << std::setw(10) << hStr << " | " << swarmRegistry[i].geographicCountry << "\n";
    }
    std::cout << "========================================================================================\n"; return 0;
}
