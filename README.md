# 🪐 Qmask Core — High-Performance Peer Swarm, Ledger Infrastructure & Governance Engine

Welcome to the definitive master specification, architectural manifest, and operational manual for the **Qmask Core Network** architecture. This suite handles a fully decentralized, high-capacity, trackerless proof-of-work asset ledger optimized natively for high-density logical computing environments.

---

## 📐 1. Architectural System Overview & Core Framework

Qmask Core shifts away from traditional, fragile server-reliant tracking paradigms to implement a fully autonomous, hard-scanned peer infrastructure layer:

*   **Trackerless Swarm Engine**: Leverages a Kademlia-style Distributed Hash Table (DHT) overlay matrix to coordinate peer routing tables entirely via serverless, non-blocking UDP/TCP socket passes over **Port 8327**.
*   **Inside-Out NAT Firewall Traversal**: Embeds automated outbound cryptographic hole-punching mechanisms within the connectivity layer. Nodes bridge data structures cleanly across remote carrier-grade firewalls without requiring manual port-forwarding modifications on home routing hardware.
*   **Hardware Instruction Optimization**: Explicitly tuned for native Zen 3 instruction execution pipelines (`-march=znver3`), unlocking max parallel throughput across high-density multi-threaded execution rigs.
*   **Moving Average Dynamic Difficulty Retargeting**: Bypasses easily manipulated static difficulty parameters. The engine automatically samples block timestamp metadata precisely every **10 blocks**, adjusting the cryptographic calculation filter dynamically to protect a strict **60-second mainnet block target target**.
*   **Fluid Token Governance (FTG)**: Implements true computational democracy via the `SHARE_FTG` protocol layer. Miners vote directly with processing power by stamping their legislative choices directly into active block headers.
*   **Maturity Vault Protection**: Enforces a firm **100-block maturity lock** on newly generated coinbase blocks. Minted coins are held securely within an immature state until the network stacks sufficient verification depth to isolate the rewards from split-second chain reorganizations.
*   **Cryptographic Snapshot Escrow & Vesting Engine**: Secures network stability by anchoring the entire **1,675,180.00 QMK legacy supply** inside a master holding vault. Transactions attempting to move un-verified pre-fork coins are automatically rejected (`INVALID_LEGACY_TRANSITION`), enabling a controlled, programmatically regulated release velocity curve pending governance results.

---

## 📊 2. Network Economic Profile & Specification

*   **Block Reward Baseline**: Flat `5.00000000 QMK` per block allocation.
*   **Maturity Velocity Threshold**: `100 Blocks` depth confirmation required.
*   **Target Block Target Cadence**: `60 Seconds` automated dynamic target windows.
*   **Dynamic Retarget Calculation Clock**: Evaluated every `10 Blocks` cleanly.
*   **Ecosystem Emission Hard Cap**: `21,000,000.00000000 QMK` absolute max supply ceiling.
*   **Default Mainnet Connection Port**: `8327` (P2P Mesh Swarm Routing).
*   **Embedded RPC Telemetry Port**: `8328` (Embedded HTTP JSON Analytics Engine).

---

## 🏃‍♂️ 3. Operational Command Reference Manual

Use the following definitive execution blocks inside your active system terminals to deploy, query, and interact with the network layers:

### 🟢 Launching the Core Mining Server Daemon
```bash
./qmask_daemon_linux   # For Linux Server Environments
qmask_daemon.exe       # For native Windows Command Prompt paths
```
*Purpose*: Spawns the node workspace, allocates all 32 logical execution tracks at 100% processing capacity, connects to available DHT mesh peers, and initializes the background web analytics handlers.

### 📊 Querying the Live Telemetry Control Center (One-Click Setup)
Run this loop natively inside your terminal window to track real-time dashboard data streams:
```bash
while true; do clear; echo \"=========================================================\"; echo \"        QMASK MASTER SWARM & TELEMETRY CONTROL CENTER    \"; echo \"=========================================================\"; echo \"Timestamp      : \$(date +\"%Y-%m-%d %H:%M:%S\")\"; cd /mnt/c/Users/user/Desktop/Qmask-Core/build; echo \"Network Status : MAINNET_OPERATIONAL\"; echo \"---------------------------------------------------------\"; ./moneu-cli getmininginfo; echo \"=========================================================\"; echo \"Tracking live system updates... Press [Ctrl + C] to exit.\"; sleep 10; done
```
*Alternatively*: Double-click the **`Launch_Qmask_Telemetry.bat`** macro file on your Windows desktop grid layout to execute this script instantly in a dedicated shell window.

### 💰 Checking Spendable Ledger Balances
```bash
./moneu-cli getbalance
```
*Purpose*: Returns your fully-matured, spendable asset totals currently available to your local address.

### 🔍 Extracting Advanced System Wallet Status Reports
```bash
./moneu-cli getwalletinfo
```
*Purpose*: Prints the comprehensive tracking matrix, including matured portfolio counts, immature locked vault pools, circulating economy counts, hashrate speedometer performance (H/s), blocks remaining until difficulty retargets, and the status parameters of the Snapshot Escrow Vault.

---

## 🗳️ 4. Forked Balance Transitions & Governance Actions

### 🔀 Step-by-Step Manual Fork Balance Transfer
To connect your historical balances from the old Moneu codebase and copy them 1:1 into the upgraded Qmask Core ecosystem, execute this folder migration pass directly inside your subsystem terminals:
```bash
# 1. Enter your root workspace directory path
cd ~

# 2. Duplicate your empty newly-generated Qmask wallet configuration layout as a backup asset
cp ~/.qmask/wallet.json ~/.qmask/wallet_backup.json

# 3. Securely overwrite the new key files with your authentic historical Moneu key vault
cp ~/.moneu/wallet.json ~/.qmask/wallet.json
```
*Outcome*: Upon launching your telemetry dashboards next, your CLI tool will automatically detect your old public identity address signature, parse the blockchain database, and reflect your forked balances inside your terminal records.

### 🗳️ Executing On-Chain Governance Voting Stances via SHARE_FTG
Qmask separates voting from coin ownership to protect decentralization. Miners vote on network referendums (such as the fate of the 1.67 Million snapshot vault—to Burn, Vest, or Donate) directly using processing power.
1. To register your block validation voting preference, access your consensus layout files (`src/main.cpp`).
2. Map your legislative ballot option strings cleanly inside your target verification arrays.
3. Your 32 cache-aligned cores will automatically stamp your preferred ballot identity directly into every found block header (`SHARE_FTG Voting Pipeline Engaged`).
4. Connected network peers parse your header stamps live, counting your computing uptime as active legislative votes to lock in new protocol rules across mainnet blocks automatically.

---

## 🛠️ 5. Multi-Platform Cross-Compilation Matrix

To re-build both decoupled multi-binary utility targets from fresh source text without using cached makefile states, use these clean compiler pass chains:

### 🐧 Native Linux Production Target Build Pass
```bash
cd /mnt/c/Users/user/Desktop/Qmask-Core/src
g++ -O3 -march=znver3 -std=c++17 main.cpp net.cpp setup_wizard.cpp tactics_core.cpp -o ../build/moneud -lpthread
g++ -O3 -march=znver3 -std=c++17 wallet_cli_entry.cpp wallet_guard.cpp setup_wizard.cpp net.cpp tactics_core.cpp -o ../build/moneu-cli -lpthread
```

### 🪟 Windows Target Cross-Compilation Pass (via MinGW Subsystem)
```bash
cd /mnt/c/Users/user/Desktop/Qmask-Core
x86_64-w64-mingw32-g++ -O3 -std=c++17 -I./src src/main.cpp src/net.cpp src/setup_wizard.cpp src/tactics_core.cpp -o build/qmask_daemon.exe -static -lws2_32 -lwinmm
x86_64-w64-mingw32-g++ -O3 -std=c++17 -I./src src/wallet_cli_entry.cpp src/net.cpp src/setup_wizard.cpp src/wallet_guard.cpp src/tactics_core.cpp -o build/qmask_cli.exe -static -lws2_32 -lwinmm
```
*Note*: Compiled cross-compilation binaries populate directly inside the `/build` tracking directory, ready to be compressed straight into your permanent desktop repository vault (**`Qmask_All_Swarm_Zips`**).
