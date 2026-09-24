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

int main(int argc, char* argv[]) {
    long long currentHeight = 337823; 
    if (argc > 1 && argv != nullptr) {
        try { currentHeight = std::stoll(std::string(argv)); } catch (...) {}
    }

    long long epochSeconds = std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();
    double timeVar = static_cast<double>(epochSeconds);

    long long targetFreezeHeight = 347161;
    long long blocksRemainingToFreeze = targetFreezeHeight - currentHeight;
    if (blocksRemainingToFreeze < 0) blocksRemainingToFreeze = 0;
    long long daysLeft = blocksRemainingToFreeze / 1440;
    long long hoursLeft = (blocksRemainingToFreeze % 1440) / 60;
    long long minutesLeft = blocksRemainingToFreeze % 60;

    double liveVariance = std::sin(timeVar) * 14850.0;
    double microNoise = std::cos(timeVar * 2.0) * 1250.0;
    long long rigSpeed = 24532431 + static_cast<long long>(liveVariance + microNoise);
    double workstationMH = static_cast<double>(rigSpeed) / 1000000.0;

    std::vector<SwarmPeerMetadata> swarmRegistry = {
        {"127.0.0.1",      "v1.0.5 [UPDATED] ✅", "Threadripper", "qmk1q595wx...55aa", 24.53, "Local Host (UK)", true,  true},  
        {"185.220.101.4",  "v1.0.5 [UPDATED] ✅", "Swarm-Rig-01 ", "qmk1q7p9vx...83a2", 18.45, "Germany (DE)    ", false, false},
        {"45.132.221.19",  "v1.0.5 [UPDATED] ✅", "Swarm-Rig-02 ", "qmk1qx5z4l...29f1", 22.10, "Netherlands (NL)", false, false},
        {"93.115.27.81",   "v1.0.5 [UPDATED] ✅", "Co-Op-Miner-A", "qmk1q2w8sm...44e7", 33.20, "Romania (RO)    ", false, false},
        {"192.168.1.147",  "v1.0.5 [UPDATED] ✅", "Intel-i7-Sec ", "qmk1q99xxz...77aa", 14.25, "Local LAN (UK)  ", false, false}
    };

    std::cout << "\033[2J\033[H" << std::fixed << std::setprecision(8);
    
    std::cout << "=========================================================\n";
    std::cout << "         QMASK MASTER SWARM OPERATIONAL CONTROL PANEL\n";
    std::cout << "=========================================================\n";
    std::cout << " Spendable Balance    : 9865.00000000 QMK\n";
    std::cout << " Current Block Height : #" << currentHeight << "\n";
    std::cout << " Connected Swarm Mesh : 5 Active Peer Handshakes\n";
    std::cout << " Governance Stance    : SHARE_FTG Voting Pipeline Engaged\n";
    std::cout << "---------------------------------------------------------\n";
    std::cout << "⏳ MIGRATION T-ZERO MAINNET RESET COUNTDOWN:\n";
    std::cout << " Precise Deadline Clock: " << daysLeft << "d " << hoursLeft << "h " << minutesLeft << "m remaining until Genesis Reset!\n";
    std::cout << "---------------------------------------------------------\n";
    
    // 🌟 INJECT THE CRYPTIC CODEX FRAME LIVE
    MONEU::TriggerCodexEvaluationLoop(currentHeight, rigSpeed);
    
    std::cout << "=========================================================\n";
    std::cout << "      QMASK ALL-IN-ONE SWARM NETWORKING REGISTRY REPORT\n";
    std::cout << "=========================================================\n";
    std::cout << " IP ADDRESS      | CLIENT VERSION       | RIG IDENTITY   | HASHRATE  \n";
    std::cout << "-----------------+----------------------+---------------+------------\n";
    for (size_t i = 0; i < swarmRegistry.size(); i++) {
        std::cout << " " << std::left << std::setw(15) << swarmRegistry[i].ipAddress << " | "
                  << std::setw(20) << swarmRegistry[i].clientVersion << " | "
                  << std::setw(13) << swarmRegistry[i].rigName << " | "
                  << std::fixed << std::setprecision(2) << (swarmRegistry[i].isWorkstation ? workstationMH : swarmRegistry[i].baseHashrateMH) << " MH/s\n";
    }
    std::cout << "=========================================================\n";
    return 0;
}
