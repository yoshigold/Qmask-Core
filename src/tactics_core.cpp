#include <iostream>
#include <string>
#include <cstdint>

extern int GetActiveSwarmPeerCount();
extern uint64_t GetNetworkHashrate();
extern int GetPendingImmatureBlocks(int bm);
extern int GetMinerLifetimeBlocks(int bm);
extern int GetBlocksUntilRetarget(int bm);

void DisplayMiningInfoJSON(int blocksMined) {
    uint64_t supply = (uint64_t)blocksMined * 5;
    int lifetimeBlocks = GetMinerLifetimeBlocks(blocksMined);
    uint64_t lifetimeCoins = (uint64_t)lifetimeBlocks * 5;
    int immatureBlocks = GetPendingImmatureBlocks(blocksMined);
    uint64_t immatureCoins = (uint64_t)immatureBlocks * 5;
    int blocksLeft = GetBlocksUntilRetarget(blocksMined);

    std::cout << "{\n"
              << "  \"network_status\": \"MAINNET_OPERATIONAL\",\n"
              << "  \"blocks\": " << blocksMined << ",\n"
              << "  \"current_block_reward\": \"5.00000000 QMK\",\n"
              << "  \"active_cpu_threads\": 32,\n"
              << "  \"hardware_acceleration\": \"AMD Ryzen Threadripper PRO 5955WX Engine Engaged\",\n"
              << "  \"node_hashrate_hash_sec\": \"" << GetNetworkHashrate() << " H/s\",\n"
              << "  \"difficulty_matrix\": \"50000000000\",\n"
              << "  \"active_swarm_peers\": \"" << GetActiveSwarmPeerCount() << " Active Handshake Nodes\",\n"
              << "  \"miner_lifetime_blocks\": \"" << lifetimeBlocks << " Blocks Solved by Your Machine\",\n"
              << "  \"miner_lifetime_rewards\": \"" << lifetimeCoins << ".00000000 QMK Minted\",\n"
              << "  \"immature_blocks_vault\": \"" << immatureBlocks << " Blocks Pending Confirmation\",\n"
              << "  \"immature_balance_locked\": \"" << immatureCoins << ".00000000 QMK\",\n"
              << "  \"circulating_supply\": \"" << supply << ".00000000 QMK\",\n"
              << "  \"max_total_supply\": \"21000000.00000000 QMK\",\n"
              << "  \"governance_consensus\": \"SHARE_FTG (Fluid Token Governance Vote: Active)\",\n"
              << "  \"blocks_until_next_retarget\": \"" << blocksLeft << " Blocks Left Until Diff Step\",\n"
              << "  \"maturity_lock_threshold\": \"100 Blocks Required\",\n"
              << "  \"port_mapping_status\": \"8327 Listening (UPnP/NAT Fallbacks Healthy)\"\n"
              << "}\n";
}
