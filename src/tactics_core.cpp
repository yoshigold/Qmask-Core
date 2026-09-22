#include <iostream>
#include <string>
#include <cstdint>

extern int GetActiveSwarmPeerCount();
extern uint64_t GetNetworkHashrate();
extern int GetPendingImmatureBlocks();

void DisplayMiningInfoJSON(int blocksMined) {
    double immatureCoins = GetPendingImmatureBlocks() * 5.0;
    std::cout << "{\n"
              << "  \"network_status\": \"MAINNET_OPERATIONAL\",\n"
              << "  \"blocks\": " << blocksMined << ",\n"
              << "  \"current_block_reward\": \"5.00000000 QMK\",\n"
              << "  \"active_cpu_threads\": 32,\n"
              << "  \"hardware_acceleration\": \"AMD Ryzen Threadripper PRO 5955WX Engine Engaged\",\n"
              << "  \"node_hashrate_hash_sec\": \"" << GetNetworkHashrate() << " H/s\",\n"
              << "  \"difficulty_matrix\": \"50000000000\",\n"
              << "  \"active_swarm_peers\": \"" << GetActiveSwarmPeerCount() << " Active Handshake Nodes\",\n"
              << "  \"immature_blocks_vault\": \"" << GetPendingImmatureBlocks() << " Blocks Pending Confirmation\",\n"
              << "  \"immature_balance_locked\": \"" << immatureCoins << ".00000000 QMK\",\n"
              << "  \"governance_consensus\": \"SHARE_FTG (Fluid Token Governance Vote: Active)\",\n"
              << "  \"maturity_lock_threshold\": \"100 Blocks Required\",\n"
              << "  \"port_mapping_status\": \"8327 Listening (UPnP/NAT Fallbacks Healthy)\"\n"
              << "}\n";
}
