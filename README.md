# Qmask Core & ChronoPulse Privacy Protocol (v1.0.5 Fortified)
### The Sovereign Decentralised, Multi-Stage CPU-Proof Network Ledger
---

## 🛰️ 1. Executive Protocol Abstract & Architectural Philosophy

Qmask Core represents a structural departure from legacy, linear proof-of-work protocols. While early cryptographic ledgers relied on static mathematical hashing functions that inevitably succumbed to industrial hardware centralisation (ASICs) or massive server farm hijacking (NiceHash rentals), Qmask introduces a fluid, hardware-bound, self-mutating ecosystem. 

Architected explicitly for high-parallel, multi-threaded processor units—specifically optimised for the architectural thresholds of systems like the **AMD Ryzen Threadripper PRO 5955WX (32 Cores / 64 Threads)** and secondary consumer chips like the **Intel i7-14700**—the network ensures absolute mining decentralisation right inside its consensus silicon code.

By combining an append-only **Merkle Mountain Range (MMR) UTXO tracking matrix** with constant-time **Kimchi Polynomial Folding zero-knowledge primitives**, Qmask breaks the dependency between high-anonymity transaction sets and ledger weight. The network achieves a strict O(1) scaling factor while validating thousands of cryptographic proof decoys. 

Currently operating in its **Fortified Testing Phase**, the network is executing a strict decentralised governance referendum code track (**SHARE_FTG**) to determine its final production parameters before migrating to an ultra-light mainnet genesis reset.

---

## 🗳️ 2. The Fair Launch & SHARE_FTG Referendum Manifesto

Qmask enforces an absolute **Fair Launch Principle**. There are no venture capital allocations, no pre-mines hidden from the public, and no centralized development foundation taxes. Every single block token is minted natively through pure proof-of-work verification. 

The current voting pipeline, named **SHARE_FTG (For The Governance / Fair Token Growth)**, is a mathematical checkpoint running directly inside the block header validation loops to let the active mining community decide the network's production identity.

### 📊 Referendum Timeline & Evaluation Metrics
* **Initial Testing Height:** Block #337,081
* **Evaluation Window:** 5 intervals of 2,016 blocks each (10,080 Blocks Total)
* **Target Mainnet Freeze Anchor:** Block #347,161
* **Network Consensus Cadence:** The high-velocity **ASERT difficulty adjustment engine** has stabilized block generation times to an exact average of **60 seconds**. This translates to 1.4 days per interval, locking the total testing lifecycle to exactly **7 Days (1 Full Week)**.
* **The Activation Threshold:** A strict **75% network approval rate** is required (7,560 out of 10,080 block headers must carry your node's affirmative voting signature to pass a metric).
* **The Final Countdown Deadline:** The testing phase will officially terminate at Block #347,161, executing on **September 30, 2026, at approximately 8:32 PM BST**.

---

## 🧬 3. Comprehensive Deep-Dive Feature Analysis

### 🛡️ A. The ChronoPulse Hashing Engine & Silicon Mixing
The consensus layer replaces primitive single-function hashing algorithms with an unbroken, multi-stage hardware-bound pipeline. Every block header submitted to the swarm must sequentially clear all stages:
* **Linear Time-Interval Mutations:** Inner cryptographic state paths automatically rewrite themselves every 600 seconds (10 minutes) based on temporal epoch clocks, preventing static ASIC loop mapping.
* **Random Block Mutations:** Bitwise circular shifts and variable branching vectors shuffle dynamically based on the unique block height entropy of previous headers.
* **L3 Cache Saturation Matrix:** Forces sequential memory hardening (SMR) loops that allocate exactly 2MB of memory footprint per execution thread. This saturates the CPU L1/L2/L3 cache line boundaries, causing heavy graphics cards (GPUs) or specialized ASIC chips to throttle and drop off the network.
* **Native 64-Bit Register Acceleration:** Leverages advanced integer multipliers that execute directly inside the Arithmetic Logic Units (ALUs) of modern CPUs via AVX vector simulation registers.

### ⚡ B. Logarithmic Data Scaling & Linear Pruning
* **Kimchi Polynomial Folding:** Traditional privacy solutions increase data mass linearly with the number of decoy mixins. Qmask collapses ring commitments down to a constant-time footprint of **96 bytes per input**, allowing up to 65,536 extreme decoys to verify instantly without bloating disk blocks.
* **Merkle Mountain Range (MMR):** Prunes historic transaction logs by sealing current UTXO balances inside append-only roots in the block headers, allowing immediate **Headers-First Synchronization**.
* **UTXO Snapshot Engine:** A production tool built into consensus designed to compress the state records of over 300,000 legacy or invalid testnet blocks into a streamlined, high-density C++ data array matrix.

### 🔒 C. Active Network Port Defense Shield
* **Dual-Port Protocol Isolation:** Segregates internet communication into two isolated lines: Public Port **`8328`** handles public ledger routing and block sync streams, while Private Port **`8329`** hosts an encrypted side-channel reserved strictly for zero-knowledge data exchanges and hidden node communications.
* **Adaptive Peer Throttler:** Tracks peer handshakes using a real-time misbehavior point penalty index. Any outdated node (`v1.0.4 [STUCK]`) or bad actor trying to flood sockets is given an immediate 100-point penalty, disconnecting and banning the IP instantly to preserve bandwidth.
* **Arbitrary In-Block Inscription Engine:** Provides direct protocol commands to permanently write cryptic messages or cryptographic snapshots natively into the block stream arrays.

---

## 🖥️ 4. Master Telemetry Dashboard & Panel Interface Guide

When executing the monitoring environment loop, the system draws a double-buffered, non-scrolling matrix operator dashboard explicitly mapped to coordinates (0,0) to block any viewport glitching or scrollback leaks.

---

## 🗳️ 5. COMPLETE GOVERNANCE REFERENDUM COMMAND TREE MANUAL

Operators running nodes on the network can pass parameters during daemon startup to cast active cryptographic signatures on the upcoming mainnet migration boundaries.

### 🔀 A. Pre-Testnet & Initial Testing Coins Allocation Vote
Governs the treatment of the initial coin supply tracked during the pre-testnet network bootstrapping phase:
* **Vote to BURN Initial Testing Coins:**
  ```bash
  ./build/moneusd -daemon -initial_supply=burn
  ```
  *Description: Destroys all initial pre-testnet coin pools provably on mainnet launch.*
* **Vote to VEST Initial Testing Coins:**
  ```bash
  ./build/moneusd -daemon -initial_supply=vest
  ```
  *Description: Places initial supply into a linear 12-month cryptographic vesting smart lock.*
* **Vote to SHARE Initial Testing Coins:**
  ```bash
  ./build/moneusd -daemon -initial_supply=share
  ```
  *Description: Pro-ratas the initial supply evenly among all active verified v1.0.5 testing nodes.*

### 🛡️ B. Forked Balance Transfer Governance Suite (QMS Shadow Fork)
Dictates how the upcoming private shadow network fork (Quantum Mask Shadow - QMS) handles balance inheritances from the primary ledger:
* **Vote to BURN Forked Balance Transfers:**
  ```bash
  ./build/moneusd -daemon -fork_transfer=burn
  ```
  *Description: Prevents the shadow network from inheriting any historic coin distribution paths, enforcing a clean zero-supply privacy launch.*
* **Vote to VEST Forked Balance Transfers:**
  ```bash
  ./build/moneusd -daemon -fork_transfer=vest
  ```
  *Description: Restricts immediate shadow fork liquidity by placing inherited balances inside a timelock vault.*
* **Vote to SHARE Forked Balance Transfers:**
  ```bash
  ./build/moneusd -daemon -fork_transfer=share
  ```
  *Description: Enables an instant 1:1 balance drop matching your current QMC balances straight onto the active private ports of the QMS network.*

### 🏷️ C. Mainnet Token Ticker Referendum Ballot
* Vote for Option 1 (QMC - Quantum Mask Coin Base Baseline): `./build/moneusd -daemon -voteticker=QMC`
* Vote for Option 2 (QMS - Quantum Mask Shadow Protocol): `./build/moneusd -daemon -voteticker=QMS`
* Vote for Option 3 (QMT - Quantum Mask Terminal Transit Line): `./build/moneusd -daemon -voteticker=QMT`
* Vote for Option 4 (QMX - Quantum Mask Matrix Mutator Engine): `./build/moneusd -daemon -voteticker=QMX`

---

## 6. Local Key Generation & Physical Noise Entropy Operation

#### Generate a Brand New Cryptographic Mainnet Keypair Wallet Address
```bash
./build/moneu-cli generateaddress
```

#### Seed the Core Engine with Raw Physical Background Noise Entropy
```bash
cat /proc/interrupts /proc/crypto > /tmp/live_block.dat
```

#### Read the Hidden Block 1 Cryptic Inscription Payload Natively
```bash
./build/moneu-cli getblock 1
```

#### Send a Live Cryptographic Test Transfer across Local LAN Mesh Ports
```bash
./build/moneu-cli --send qmk1q99xxz...77aa 500.00
```

---

## 🧐 7. Comprehensive Expert Protocol Analysis & Diagnostic Feedback

### 🚀 Strengths & Structural Innovations
1. **ASIC & Rental Server Elimination:** The execution loop of ChronoPulse provides excellent protection. ASICs excel at processing static, predictable hashing circuits. By dynamically changing code structures every 10 minutes based on block time and height mutations, you have built a system where hardware must adapt on the fly. This turns the physical architecture of a multi-core CPU into the only efficient mechanism for block validation.
2. **Excellent Memory Design:** Forcing a strict 2MB memory block allocation per execution thread lines up with the L3 cache configuration of modern desktop processors. This allows your Threadripper PRO's 64MB L3 Cache to run 32 mining worker threads natively without context thrashing, while multi-GPU mining rigs will immediately choke on the massive memory access bottlenecks.
3. **Decoupled Growth via MMR:** Traditional Bitcoin forks suffer from slow sync speeds as the chain climbs. The implementation of Merkle Mountain Ranges enables headers-first verification, meaning the network can scale indefinitely while maintaining lightning-fast initial node synchronization speeds.

### 🔮 Strategic Future Outlook
Qmask Core has successfully established its computational, network routing, and data compression layers. The architecture is perfectly aligned to transition into an absolute sovereign asset. Once the governance evaluation window hits its Block #347,161 freeze barrier, executing the automated UTXO compression manifest will allow you to drop thousands of invalid historic blocks, launching an elite, ultra-light production blockchain built to scale securely for decades.
