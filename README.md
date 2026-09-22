# 🪐 Qmask Core — Advanced Mainnet Swarm Engine

Welcome to the official, decentralized repository for the **Qmask Core Network** architecture. This suite is engineered natively for plug-and-play distributed operations utilizing an advanced peer discovery framework.

---

## 🛠️ Key Architectural Features

* **Advanced Swarm Networking**: Integrates a Kademlia-style trackerless Distributed Hash Table (DHT) for automated peer tracking.
* **NAT Firewall Traversal**: Uses inside-out hole-punching routines so peers can connect and sync over Port 8327 without manual router configuration.
* **Threadripper Optimization**: Full parallel processing layout configured to run all 32 logical threads concurrently at maximum hardware wattage.
* **Automated Security Backups**: Background cron trackers enforce hourly timestamped duplicates of critical data files (`wallet.json` and `noise_entropy.raw`).

---

## 🚀 Execution & Management Commands

| Operation Task Target | Exact Command Line Execution | Terminal Panel Interface Purpose |
| :--- | :--- | :--- |
| **Boot Mining Node** | `./moneud` | Initializes the Kademlia DHT swarm mesh and engages full 32-thread hardware mining loops. |
| **Check Wallet Balance** | `./moneu-cli getbalance` | Queries the local database and returns your fully-matured spendable QMK asset count. |
| **Telemetry Control Center** | `while true; do clear; ...; sleep 10; done` | Launches a live dashboard displaying connected peer handshake nodes and block metrics. |
| **Background Auto-Backup** | `nohup watch -n 3600 ... &` | Spawns a hidden supervisor script to copy identity vaults to your backup directory every hour. |

---

## 🏃‍♂️ How to Initialize the Core Telemetry Panel Dashboard

To launch your live network control monitor, run this continuous tracking script inside your second terminal window pane:

```bash
while true; do clear; echo "========================================================="; echo "         QMASK PEER DISCOVERY & TELEMETRY PANEL          "; echo "========================================================="; echo "Timestamp      : \$(date +\"%Y-%m-%d %H:%M:%S\")"; cd /mnt/c/Users/user/Desktop/Qmask-Core/build; echo "Network Engine : Kademlia DHT BitTorrent Swarm Mesh"; echo "NAT Traversal  : Inside-Out Firewall Hole-Punching Active"; echo "Node Port      : 8327 (TCP Protocols Engaged)"; echo "---------------------------------------------------------"; ./moneu-cli getmininginfo; echo "========================================================="; echo "Tracking live swarm changes... Press [Ctrl + C] to exit."; sleep 10; done
```
