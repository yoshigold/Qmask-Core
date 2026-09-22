# 🪐 Qmask Core — High-Performance Peer Swarm & Ledger Infrastructure Engine

Welcome to the master technical specification and execution guide for the **Qmask Core Network** architecture. This project implements a fully decentralized, trackerless P2P asset ledger designed from the ground up for high-capacity multithreaded hardware deployment.

---

## 📐 1. Architectural System Overview

Qmask Core bypasses traditional centralized tracking paradigms in favour of a fully autonomous distributed service topology:

*   **Trackerless Swarm Engine**: Leverages a Kademlia-style Distributed Hash Table (DHT) overlay network for serverless peer discovery. Nodes register, announce, and trace topology routing arrays entirely via parallel UDP/TCP iterations.
*   **Inside-Out NAT Firewall Traversal**: Integrates inside-out hole-punching routines natively into the network layer. Users bridge data frames seamlessly across remote firewalls without requiring manual port-forwarding modifications on consumer routers.
*   **Hardware Architecture Optimization**: The processing path is explicitly tuned for native Zen 3 micro-instruction sets (`-march=znver3`), unlocking parallel compute efficiency across high-density logical environments.
*   **Fluid Token Governance (FTG)**: Embeds cryptographic on-chain consensus flags directly inside active validation blocks to regulate network emission rules dynamically.
*   **Maturity Vault Protection**: Features an enforced **100-block maturity confirmation vault** to lock newly generated coinbase mining rewards, protecting asset distribution pipelines from chain reorganizations.

---

## 🗄️ 2. Repository Core File Inventory

The source layout splits server synchronization engines from client management interfaces cleanly:
*   `src/main.cpp` — Primary execution entry tracking path orchestrating core background mining loops.
*   `src/net.cpp` — Decentralized network swarm telemetry socket configurations and peer tracking links.
*   `src/wallet_cli_entry.cpp` — Client command-line parsing router tree handling diagnostic reporting queries.
*   `src/cold_matrix.cpp` — Cross-platform localized filesystem serialization and key storage components.
*   `src/tactics_core.cpp` — Global RPC JSON output data formatter string mapping modules.

---

## 🏃‍♂️ 3. Operational Command Reference Manual

Use the following definitive execution sequences inside your terminal workspaces to manage active nodes:

### 🟢 Launching the Mining Server Daemon
```bash
./qmask_daemon_linux   # For Linux systems
qmask_daemon.exe       # For Windows Command Prompt
```
*Purpose*: Spawns the worker matrix, allocations all 32 logical threads at 100% processing load, engages the 50 Billion difficulty filter, and hosts the ledger seed files over port 8327.

### 📊 Querying the Live Telemetry Control Center Loop
```bash
while true; do clear; echo \"=========================================================\"; echo \"        QMASK MASTER SWARM & TELEMETRY CONTROL CENTER    \"; echo \"=========================================================\"; echo \"Timestamp      : \$(date +\"%Y-%m-%d %H:%M:%S\")\"; cd /mnt/c/Users/user/Desktop/Qmask-Core/build; echo \"Network Status : MAINNET_OPERATIONAL\"; echo \"NAT Traversal  : Inside-Out Firewall Hole-Punching Active\"; echo \"---------------------------------------------------------\"; ./moneu-cli getmininginfo; echo \"=========================================================\"; echo \"Tracking live system updates... Press [Ctrl + C] to exit.\"; sleep 10; done
```
*Purpose*: Locks your monitor screen into a live diagnostic control room, updating peer connections, immature balances, and computing speeds every 10 seconds.

### 💰 Checking Matured Wallet Balances
```bash
./moneu-cli getbalance
```
*Purpose*: Directly outputs your fully spendable, post-maturity account balances.

### 🔍 Extracting Deep Wallet Status Metrics
```bash
./moneu-cli getwalletinfo
```
*Purpose*: Prints the comprehensive system wallet report, showing spendable totals, immature locked tokens, target lock confirmation depths, and active unique founder account address hashes.

---

## 🛠️ 4. Multi-Platform Cross-Compilation Matrix

To compile the latest telemetry configurations from source files without build cache dependencies, run the following isolated toolchain blocks:

### 🐧 Native Linux Production Target Build
```bash
cd /mnt/c/Users/user/Desktop/Qmask-Core/src
g++ -O3 -march=znver3 -std=c++17 -include sys/stat.h -include sys/types.h -D\"mkdir(a,b)=mkdir(a,b)\" main.cpp net.cpp setup_wizard.cpp tactics_core.cpp -o qmask_daemon_linux -static-libgcc -static-libstdc++ -lpthread
g++ -O3 -march=znver3 -std=c++17 -include sys/stat.h -include sys/types.h -D\"mkdir(a,b)=mkdir(a,b)\" wallet_cli_entry.cpp wallet_guard.cpp setup_wizard.cpp net.cpp tactics_core.cpp -o qmask_cli_linux -static-libgcc -static-libstdc++ -lpthread
```

### 🪟 Windows Target Cross-Compilation Pass (via MinGW Subsystem)
```bash
cd /mnt/c/Users/user/Desktop/Qmask-Core
x86_64-w64-mingw32-g++ -O3 -std=c++17 -I./src src/main.cpp src/net.cpp src/setup_wizard.cpp src/cold_matrix.cpp src/tactics_core.cpp -o build/qmask_daemon.exe -static -lws2_32 -lwinmm
x86_64-w64-mingw32-g++ -O3 -std=c++17 -I./src src/wallet_cli_entry.cpp src/net.cpp src/setup_wizard.cpp src/wallet_guard.cpp src/cold_matrix.cpp src/tactics_core.cpp -o build/qmask_cli.exe -static -lws2_32 -lwinmm
```
