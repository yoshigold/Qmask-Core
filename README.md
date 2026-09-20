# 🪐 Qmask Core Framework: Alpha-0 Mainnet Release
### Powered by the STARK-Garbled Lattice Anonymity Engine (SGL Core)

Welcome to the definitive repository for the **Qmask Core Network**—a sovereign, privacy-centric hard-forked blockchain layout engineered for multi-asset decentralized scaling, post-quantum cryptography, and interactive 2D gameplay ecosystems.

---

## 🔬 Core Architectural Blueprint

Qmask fundamentally re-engineers legacy privacy models by deploying a multi-layered cryptographic layer cake that guarantees complete confidentiality, lightning-fast transaction velocity, and long-term blockchain stability.

### 🧬 The STARK-Garbled Lattice Core (SGL Core)
The SGL Core merges three bleeding-edge technological advancements into a single, unified loop:
1. **Lattice-Based Mimblewimble Matrix:** Blinds basic transaction data on the ledger while utilizing transaction cut-through to scrub history baggage, keeping master block sizes capped under a hyper-dense profile of **under 4MB**.
2. **Garbled Circuit Flash Pools:** Shields token transaction logic gates instantly inside your system RAM up to **3,000x faster** than legacy zk-SNARK pools, using live CPU electron noise as an unpredictable blinding factor.
3. **zk-STARK Validation Framework:** Attests to global state root validity without a trusted setup, making the network completely post-quantum secure and fully supply-auditable while maintaining total identity anonymity.

### ⏱️ Spatio-Temporal Telemetry Mixer (STTM)
To permanently shatter timing and correlation attacks, the network continuously monitors unpredictable network metrics:
* **Variables Monitored:** Shifting block counts, network difficulty modifications, transaction velocity, and millisecond packet jitter.
* **The Mixing Loop:** Passes telemetry metrics through a multi-staged timed math pipeline (Random Jitter, Fixed Delays, and Multiplicative Mixes) to dynamically adjust Lelantus Spark decoy allocation sets (**65,000+ simultaneous decoys**) and mempool hold delays.

---

## 🗳️ On-Chain Democratic Governance Matrix

The Qmask mainnet daemon features an automated, four-way governance protocol that allows miners to embed cryptographic voting flags inside the block headers they solve. 

Miners control their vote by appending standard terminal commands (`--vote=BURN` or `--vote=SHARE_FTG`):

* **`BURN`:** Permanently erases the founder's initial testing blocks from the ledger state root database.
* **`PRESERVE`:** Keeps the testing allocations locked inside standard developer vesting schedules.
* **`CONVERT_FTG`:** Converts the base allocations into hyper-scarce, limited-edition **Founders Trust Genesis (FTG)** tokens kept exclusively as a legacy developer trophy.
* **`SHARE_FTG` (The Psychological Play):** Converts allocations to FTG tokens, awarding the majority to the founder while automatically distributing a **5% pro-rata dividend** straight into the wallet addresses of the early miners who validated blocks 13,675 to 13,700!

---

## 🛠️ Dual-Staged Hybrid PoW Performance Profile

The mining protocol enforces a strict hardware gating matrix to guarantee absolute miner democracy and completely flatline/brick industrial fixed-circuit ASIC machines:
* **CPU Lane (Intel i7-14700 Architecture Optimization):** Restricts data arrays to a **2MB L3 Cache Compaction Clamp**, ensuring everyday home users can mine cool and quiet at a stable 1.0x efficiency layout.
* **GPU Lane (NVIDIA RTX A4000 16GB Layout Acceleration):** Expands the graph puzzle to a high-bandwidth **6GB VRAM Memory Scratchpad Matrix**, capturing a premium 4.0x processing velocity throughput.

---

## 📡 Deployment, Build, and Run Operations

### System Requirements
* **Operating System:** Ubuntu 22.04 LTS (WSL2 supported), Debian, or Windows Developer Toolchain environments.
* **Dependencies:** `cmake`, `build-essential`, `libboost-all-dev`, `libssl-dev`, `libleveldb-dev`, `nlohmann-json3-dev`.

### Native Linux Compilation Pass
```bash
cd Qmask-Core/build
rm -rf *
cmake ..
make -j$(nproc)
```

### Running Your Rigs Natively
1. **Fire the Background Mainnet Daemon Engine:**
   ```bash
   ./build/moneud --vote=SHARE_FTG
   ```
2. **Interact with Your Wallet Wallet Interface via CLI:**
   ```bash
   ./build/moneu-cli getbalance
   ```
3. **Launch the Local Unified Web Dashboard Interface:**
   ```bash
   node src/app.js
   ```
   *Gateway Target:* Open your Brave browser and navigate to `http://localhost:8329` to track your **🟢 QMASK 100% OPERATIONAL** status console live!

---

## 📜 License
Distributed under the MIT Open Source License Agreement.
