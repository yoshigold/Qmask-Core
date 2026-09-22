#include <iostream>
#include <string>

extern int GetActiveSwarmPeerCount();

void DisplayMiningInfoJSON(int blocksMined) {
    std::cout << "{\n"
              << "  \"blocks\": " << blocksMined << ",\n"
              << "  \"current_block_reward\": \"5.00000000 QMK\",\n"
              << "  \"active_cpu_threads\": 32,\n"
              << "  \"hardware_acceleration\": \"AMD Ryzen Threadripper PRO 5955WX Engine Engaged\",\n"
              << "  \"difficulty_matrix\": \"50000000000\",\n"
              << "  \"active_swarm_peers\": \"" << GetActiveSwarmPeerCount() << " Active Handshake Nodes\",\n"
              << "  \"governance_consensus\": \"SHARE_FTG (Active Core Validation)\"\n"
              << "}\n";
}
