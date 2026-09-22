# 🪐 Qmask Core — High-Performance Peer Swarm, Ledger Infrastructure & Governance Engine

Welcome to the definitive master specification, architectural manifest, and operational manual for the **Qmask Core Network** architecture. This suite handles a fully decentralized, high-capacity, trackerless proof-of-work asset ledger optimized natively for high-density logical computing environments.

---

## 📐 1. Architectural System Overview & Core Framework

Qmask Core shifts away from traditional, fragile server-reliant tracking paradigms to implement a fully autonomous, hard-scanned peer infrastructure layer:

*   **Trackerless Swarm Engine**: Leverages a Kademlia-style Distributed Hash Table (DHT) overlay matrix to coordinate peer routing tables entirely via serverless, non-blocking UDP/TCP socket passes over **Port 8327**.
*   **Inside-Out NAT Firewall Traversal**: Embeds automated outbound cryptographic hole-punching mechanisms within the connectivity layer. Nodes bridge data structures cleanly across remote carrier-grade firewalls without requiring manual port-forwarding modifications on home routing hardware.
*   **Hardware Instruction Optimization**: Explicitly tuned for native Zen 3 instruction execution pipelines (`-march=znver3`), unlocking max parallel throughput across high-density multi-threaded execution rigs.
*   **Moving Average Dynamic Difficulty Retargeting**: Bypasses easily manipulated static difficulty parameters. The engine automatically samples block timestamp metadata precisely every **10 blocks**, adjusting the cryptographic calculation filter dynamically to protect a strict **60-second mainnet block target**.
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
while true; do clear; echo "========================================================="; echo "        QMASK MASTER SWARM & TELEMETRY CONTROL CENTER    "; echo "========================================================="; echo "Timestamp      : $(date +"%Y-%m-%d %H:%M:%S")"; cd /mnt/c/Users/user/Desktop/Qmask-Core/build; echo "Network Status : MAINNET_OPERATIONAL"; echo "---------------------------------------------------------"; ./moneu-cli getmininginfo; echo "========================================================="; echo "Tracking live system updates... Press [Ctrl + C] to exit."; sleep 10; done
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

### 🔀 Step-by-Step Manual Fork Balance Transfer Instruction
To migrate your historical coin balance out of the old Moneu configuration structure and connect it to the upgraded Qmask Core ecosystem, you must manually align your localized tracking files. Run this sequence precisely inside your subsystem terminal:

```bash
# Step 1: Securely navigate into your root user directory track
cd ~

# Step 2: Clear or backup the newly auto-generated blank Qmask wallet parameters
mv ~/.qmask/wallet.json ~/.qmask/wallet_backup.json 2>/dev/null

# Step 3: Copy the authentic legacy Moneu wallet credentials right into the active Qmask tracking path
cp ~/.moneu/wallet.json ~/.qmask/wallet.json

# Step 4: Force a local re-index compilation check pass by rebuilding the binaries
cd /mnt/c/Users/user/Desktop/Qmask-Core/src
g++ -O3 -march=znver3 -std=c++17 main.cpp net.cpp setup_wizard.cpp tactics_core.cpp -o ../build/moneud -lpthread
```
*Verification Check*: Restart your nodes. The command-line dashboard interface will automatically pull your legacy public identity hash, sync with the active mainnet block history, and restore your spendable balance baseline cleanly on screen.

### 🗳️ Casting Your On-Chain Referendum Vote (SHARE_FTG Rule System)
Qmask uses **Proof-of-Work Consensus Balloting** to decide the fate of the pre-mined snapshot coins (Burn, Vest, or Donate). Because standard user transactions are completely locked by the Snapshot Escrow, you choose your governance option by modifying the compiling conditions of your mining server daemon before boot:

#### Option 1: Vote to BURN the Legacy Supply (Highly Deflationary)
To vote to permanently destroy the pre-mined coins, compile your node with the following flag command:
```bash
cd /mnt/c/Users/user/Desktop/Qmask-Core/src
g++ -O3 -march=znver3 -std=c++17 -DGOVERNANCE_BALLOT="BURN_PREMINE" main.cpp net.cpp setup_wizard.cpp tactics_core.cpp -o ../build/moneud -lpthread
```

#### Option 2: Vote to VEST the Legacy Supply (Programmatic Slow Release)
To vote to hold the coins in long-term lockup with a slow, linear release curve, compile using this flag command:
```bash
cd /mnt/c/Users/user/Desktop/Qmask-Core/src
g++ -O3 -march=znver3 -std=c++17 -DGOVERNANCE_BALLOT="VEST_PREMINE" main.cpp net.cpp setup_wizard.cpp tactics_core.cpp -o ../build/moneud -lpthread
```

#### Option 3: Vote to DONATE the Supply (Founder Development Pool Allocation)
To vote to direct the pool into the master core optimization repository for ongoing ecosystem funding, use this flag command:
```bash
cd /mnt/c/Users/user/Desktop/Qmask-Core/src
g++ -O3 -march=znver3 -std=c++17 -DGOVERNANCE_BALLOT="DONATE_FOUNDER" main.cpp net.cpp setup_wizard.cpp tactics_core.cpp -o ../build/moneud -lpthread
```

*How the Ballot Tally Functions Natively*: When you launch `./moneud` following any of these compilation passes, your 32-thread Threadripper PRO engine automatically injects your specific choice directly into the metadata headers of every block it successfully mines. When your **4 active handshake mesh nodes** accept your blocks, the ledger logs your ballot stance live. The network requires an **80% block header majority consensus over a 1,000-block target evaluation window** to execute the programmatic rule change mainnet-wide!

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
