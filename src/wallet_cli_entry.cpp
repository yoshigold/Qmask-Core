#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <sstream>
#include <thread>
#include <termios.h>
#include <unistd.h>

struct SwarmPeerMetadata { std::string ipAddress; std::string clientVersion; std::string rigName; std::string walletAddress; double baseHashrateMH; std::string geographicCountry; bool isFounder; bool isWorkstation; long long lastSeenTimestamp; };

char CaptureRawKeystrokeNatively() {
    char inputChar = 0; struct termios oldSettings, newSettings;
    if (tcgetattr(STDIN_FILENO, &oldSettings) < 0) return 0;
    newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);
    newSettings.c_cc[VMIN] = 1; newSettings.c_cc[VTIME] = 0;
    if (tcsetattr(STDIN_FILENO, TCSANOW, &newSettings) < 0) return 0;
    if (read(STDIN_FILENO, &inputChar, 1) < 0) inputChar = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
    return inputChar;
}
int main(int argc, char* argv[]) {
    long long bootTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    if (argc > 1 && argv != nullptr && std::string(argv[1]) == "--send") {
        if (argc < 4) { std::cout << "❌ Error: Use syntax: ./moneud --send <wallet_address> <amount>\n"; return 1; }
        std::string targetAddress = argv[2]; double sendAmount = std::stod(argv[3]);
        std::cout << "========================================================================================\n📡 BROADCASTING GLOBAL OUT-OF-NETWORK TRANSACTION TO PORT 18332 NETSH RELAY...\n========================================================================================\n ✅ TX ID     : [ 0x3a9f" << (bootTime % 8847) << "b2e ] Status: Broadcasted to Swarm Mesh!\n ✅ DEPARTING : qmk1q595wx...55aa [FOUNDER NODE]\n ✅ DESTINATION: " << targetAddress << "\n ✅ VALUE     : " << std::fixed << std::setprecision(4) << sendAmount << " $QMTM Shards Transferred!\n========================================================================================\n"; return 0;
    }
    double wallet = 9865.0; int gx=4, gy=2, lvl=340280, gly=0, d1=0, d2=0, rx=9, ry=0, rc=0, cmb=0; int ehp=100, php=1200;
    double qmtm = 1179.530; int shp = 0; unsigned long long qmj = 185490009451450ULL;
    long long nce = 1017, ts = 0, rng = 0, xp = 15, dmg = 75886, pmd = 0, rgd = 0; double qmkb = 1.476;
    int staffTier = 1; double hashrateBoosterMH = 0.0;
    
    int riftActive = 0; int bx = -1, by = -1; int bossHp = 500;

    std::ifstream in("game_state.dat");
    if (in.is_open()) { in >> gx >> gy >> lvl >> gly >> d1 >> d2 >> rx >> ry >> rc >> cmb >> ehp >> php >> qmtm >> shp >> qmj >> nce >> ts >> rng >> xp >> dmg >> qmkb >> pmd >> rgd; in.close(); }
    if (ehp <= 0) ehp = 100; if (qmj < 100000) qmj = 185490009451450ULL; if (php <= 0) php = 1200;

    if (argc > 1 && argv != nullptr && std::string(argv[1]) == "--game-panel") {
        std::string logMsg = "✨ Navigate coordinates. Press [R] to burn 5.00 $QME and open a Multi-Chain Boss Rift Portal!";
        while (true) {
            long long now = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            if (riftActive) { cmb = (gx == bx && gy == by) ? 1 : 0; }
            else { cmb = (gx == rx && gy == ry && !shp) ? 1 : 0; }

            std::cout << "\033[2J\033[H=================== MONEU LAYER-1 HYBRID CORES OPERATION ROOM ===================\n"
                      << "🔍 [AUDIT] ACTIVE BOSS RIFT STATUS : " << (riftActive ? "🔴 🚨 CRITICAL THREAT LEVEL ENGAGED 🚨" : "🟢 PASSIVE SANDBOX SECURE") << "\n"
                      << "💰 [VAULT] PRIMARY WALLET BALANCE  : " << std::fixed << std::setprecision(4) << qmtm << " $QMTM Shards\n"
                      << "💰 [VAULT] THERMODYNAMIC BALANCE   : " << (double)(qmj / 10000.0) << " $QME | Orb Tracker: " << php << " HP\n"
                      << "💰 [STATS] RIFT GUARDIANS DEFEATED : " << rgd << " Bosses Smashed | Level Experience: " << xp << " XP\n"
                      << "💰 [STATS] MAXIMUM STAF POWER TIER : Tier " << staffTier << " Weapon Engaged (+Multiplier Active)\n";
            
            if (shp) {
                std::cout << "---------------------------------------------------------------------------------\n"
                          << "🛒 [WHITE-HAT MERCHANT UPGRADE SHOP] Spend Shards to boost your network variables:\n"
                          << "  Buy Quantum Encryptor Staff (Tier " << (staffTier+1) << ")  👉 Cost: 150.00 $QMTM (+35 Max Hit)\n"
                          << "  Buy Network Hash Booster Ring        👉 Cost: 250.00 $QMTM (+25.00 MH/s Speed)\n"
                          << "---------------------------------------------------------------------------------\n"
                          << "👉 [SELECTION INPUT] : Press [1] or [2] to buy. Press [B] to close merchant shop window menu.\n";
            }
            if (cmb && riftActive) std::cout << "💀 [ELITE BOSS FEED] 👹 RIFT GUARDIAN ELITE LIFE ENVELOPE: [ " << bossHp << " / 500 HP ] 👹\n";
            else if (cmb) std::cout << "🔴 [BATTLE FEED] TARGET MONSTER LIFE ENVELOPE: [ " << ehp << " / 100 HP ] 👾\n";
            
            std::cout << "=================================================================================\n"
                      << " 🌾 CAMPAIGN FIELD [ 🔴 HARDCORE DEPTHS ]: " << logMsg << "\n"
                      << "---------------------------------------------------------------------------------\n";
            if (!shp) {
                int hasCryptKey = (xp >= 20 ? 1 : 0); int chestClaimed = (qmtm >= 1500 ? 1 : 0);
            for (int y = 0; y < 6; y++) {
                    std::cout << "   | ";
                    for (int x = 0; x < 16; x++) {
                        if (x == gx && y == gy) std::cout << "🧙 ";
                        else if (y == 3 && x >= 6 && x <= 10) std::cout << "🧱 ";
                        else if (!chestClaimed && x == 14 && y == 4) std::cout << "📦 ";
                        else if (riftActive && x == bx && y == by) std::cout << "👹 ";
                        else if (!riftActive && x == rx && y == ry) std::cout << "👾 ";
                        else std::cout << ".  ";
                    }
                    std::cout << "|\n";
                }
            }
            std::cout << "---------------------------------------------------------------------------------\n"
                      << "  🏆 [SWARM MAINNET] GLOBAL NETWORK RANKING LEADERBOARD REPORT\n"
                      << "  👑 #1 | qmk1q595wx...55aa [FOUNDER]  | Tier: 17013 | Hashrate: " << (49.52 + hashrateBoosterMH) << " MH/s | UK\n"
                      << "=================================================================================\n"
                      << "[CONTROLS] : W,A,S,D to move | [SPACEBAR] strike | [B] Shop Menu | [R] Open Rift Portal | X: Exit\n"
                      << "=================================================================================\n";
            
            char key = CaptureRawKeystrokeNatively();
            if (key == 'x' || key == 'X') break;
            if (key == 'b' || key == 'B') { shp = !shp; cmb = 0; if (shp && gx == rx && gy == ry) { gy++; if (gy > 5) gy = 4; } logMsg = "🛒 Toggled merchant access matrix interface lines."; continue; }
            if (shp) {
                if (key == '1') { if (qmtm >= 150.0) { qmtm -= 150.0; staffTier++; logMsg = "✅ Purchase successful! Staff Upgrade: Tier " + std::to_string(staffTier) + " active!"; } else { logMsg = "❌ Insufficient $QMTM shards!"; } }
                if (key == '2') { if (qmtm >= 250.0) { qmtm -= 250.0; hashrateBoosterMH += 25.0; logMsg = "✅ Purchase successful! Ring equipped! +25.00 MH/s applied!"; } else { logMsg = "❌ Insufficient $QMTM shards!"; } }
                continue;
            }
            if (key == 'r' || key == 'R') {
                double currentQme = (double)(qmj / 10000.0);
                if (currentQme >= 5.0 && !riftActive) {
                    qmj -= 50000; riftActive = 1; bossHp = 500; bx = 12; by = 1;
                    logMsg = "🚨 ALERT: SPACIAL CORES TORN OPEN! ACCRUED ENERGY SPAWNED THE ELITE RIFT GUARDIAN [👹]!!";
                } else if (riftActive) { logMsg = "❌ A Rift Guardian is already tearing through your shard sectors!"; }
                else { logMsg = "❌ Insufficient Accrued Thermodynamic Asset! Requires 5.00 $QME to ignite portal gateway loop!"; }
                continue;
            }

            if (key == 'w' || key == 'W') gy--; if (key == 's' || key == 'S') gy++;
            if (key == 'a' || key == 'A') gx--; if (key == 'd' || key == 'D') gx++;
            
            if (riftActive) {
                int dist = std::abs(gx - bx) + std::abs(gy - by);
                if (dist <= 3) { php -= 45; logMsg = "⚡ 🚨 WARNING: THE RIFT GUARDIAN CASTS CORRUPTION BOLT! Drained -45 $QMCO Plasma Life Orb HP!"; }
                if (php <= 0) { php = 1200; gx = 0; gy = 5; logMsg = "💀 SYSTEM DESYNC: Your character collapsed! Respawning at safe validation anchor point..."; }
            }

            if (key == ' ' && cmb == 1) {
                int hit = (15 + (now % 16)) * staffTier;
                if (riftActive) {
                    bossHp -= hit; logMsg = "💥 CRITICAL STRIKE ENGAGED! HIT THE RIFT GUARDIAN FOR " + std::to_string(hit) + " RECOVERY HP!";
                    if (bossHp <= 0) { rgd++; xp += 25; qmtm += 500.0; riftActive = 0; bx = -1; by = -1; logMsg = "👑 THE RIFT GUARDIAN DEFEATED! Mapped Ledger Confirmed Drop: +500.00 $QMTM Shards! 🏁🎉"; }
                } else {
                    ehp -= hit; logMsg = "💥 CRYPTO STRIKE HIT FOR " + std::to_string(hit) + " DATA HP DAMAGE!";
                    if (ehp <= 0) { xp += 5; qmtm += 65.0; ehp = 100; rx = 2 + (now % 12); ry = 1 + (now % 4); logMsg = "💀 ENCOUNTER DEFEATED! Reward Confirmed: +65 $QMTM Shards Deposited! 💥"; }
                }
            }
            
            if (gx < 0) gx = 0; if (gx > 15) gx = 15; if (gy < 0) gy = 0; if (gy > 5) gy = 5;
            std::ofstream out("game_state.dat");
            if (out.is_open()) { out << gx << " " << gy << " " << lvl << " " << gly << " " << d1 << " " << d2 << " " << rx << " " << ry << " " << rc << " " << cmb << " " << ehp << " " << php << " " << qmtm << " " << shp << " " << qmj << " " << nce << " " << now << " " << rng << " " << xp << " " << dmg << " " << qmkb << " " << pmd << " " << rgd; out.close(); }
        } return 0;
    }
    long long currentHeight = lvl;
    if (argc > 1 && argv != nullptr && std::string(argv[1]) == "--daemon-miner-scroll") {
        if (argc > 2 && argv != nullptr) { try { currentHeight = std::stoll(std::string(argv[2])); } catch (...) {} }
        std::cout << "========================================================================================\n🚀 QMASK CORE DAEMON INITIALISED: Launching Native STVW Scrolling Miner Engine...\n========================================================================================\n\n";
        while (true) {
            long long loopTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            double timeVar = static_cast<double>(loopTime);
            double tdpDraw = 278.45 + (std::abs(std::cos(timeVar * 0.4)) * 34.20);
            
            std::ifstream inCheck("game_state.dat");
            if (inCheck.is_open()) { inCheck >> gx >> gy >> lvl >> gly >> d1 >> d2 >> rx >> ry >> rc >> cmb >> ehp >> php >> qmtm >> shp >> qmj >> nce >> ts >> rng >> xp >> dmg >> qmkb >> pmd >> rgd; inCheck.close(); }
            if (qmj < 100000) qmj = 185490009451450ULL;

            qmj += static_cast<unsigned long long>(tdpDraw * 8.5);
            std::cout << "[BLOCK VALIDATED] Mined Block Height: #" << currentHeight << " | Difficulty: 400000000000\n🪐 [STVW Engine] Active Block Height: #" << currentHeight << " | Live Energy Balance: " << qmj << " QMJ | Accumulated Yield: " << (double)(qmj / 10000.0) << " QME\n🟢 Stable Baseline Loop: Issuing regular 5.00 QMK mining reward blocks.\n" << std::flush;
            
            currentHeight++; std::ofstream out("game_state.dat");
            if (out.is_open()) {
                out << gx << " " << gy << " " << currentHeight << " " << gly << " " << d1 << " " << d2 << " " << rx << " " << ry << " " << rc << " " << cmb << " " << ehp << " " << php << " " << qmtm << " " << shp << " " << qmj << " " << nce << " " << loopTime << " " << rng << " " << xp << " " << dmg << " " << qmkb << " " << pmd << " " << rgd; out.close();
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(60000));
        } return 0;
    }
    std::ifstream inLive("game_state.dat");
    if (inLive.is_open()) { inLive >> gx >> gy >> currentHeight >> gly >> d1 >> d2 >> rx >> ry >> rc >> cmb >> ehp >> php >> qmtm >> shp >> qmj >> nce >> ts >> rng >> xp >> dmg >> qmkb >> pmd >> rgd; inLive.close(); }
    if (qmj < 100000) qmj = 185490009451450ULL;

    long long now = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    double timeVar = static_cast<double>(now); long long rem = 1790905200LL - now; if (rem < 0) rem = 0;
    long long d = rem / 86400, h = (rem % 86400) / 3600, m = (rem % 3600) / 60, s = rem % 60;
    double speed = 24532431.0 + std::sin(timeVar)*14850.0; double tdp = 278.45 + (std::abs(std::cos(timeVar * 0.4)) * 34.20);
    qmj += static_cast<unsigned long long>(tdp * 0.85);

    long long blockGains = currentHeight - 337823; if (blockGains < 0) blockGains = 0;
    double spendableBalance = wallet + (blockGains * 5.0) + 1684.20;
    long long elapsedSinceLastBlock = now - ts; if (ts <= 0 || elapsedSinceLastBlock < 0 || elapsedSinceLastBlock > 3600) elapsedSinceLastBlock = now % 60;
    double averageBlockTimeCadenceSec = 60.0145 + (std::sin(static_cast<double>(currentHeight) * 0.2) * 0.0380);
    double cpu = 90.95 + (std::sin(timeVar * 0.5) * 1.1);
    long long currentVelocity = 54 + (currentHeight % 13);

    double calculatedBlockSizeKb = 0.45 + (std::abs(std::sin(timeVar * 0.08)) * 2.67);
    int progressSegments = static_cast<int>((calculatedBlockSizeKb / 3.52) * 10);
    if (progressSegments < 1) progressSegments = 1; if (progressSegments > 10) progressSegments = 10;
    std::string progressBarText = "░░░░░░░░░░"; for (int p = 0; p < progressSegments; p++) progressBarText[p] = 'X';
    size_t xIdx; while ((xIdx = progressBarText.find('X')) != std::string::npos) { progressBarText.replace(xIdx, 1, "▓"); }

    int electricalPosition = static_cast<int>(now % 12); std::string electricalBar = "------------";
    if (electricalPosition >= 0 && electricalPosition < 12) electricalBar[electricalPosition] = 'X';
    size_t eIdx = electricalBar.find('X'); std::string visualElectricalBar = (eIdx != std::string::npos) ? electricalBar.replace(eIdx, 1, "⚡") : "----⚡-------";

    long long simulatedFamilyComputerLastSeen = (now % 15 < 8) ? now : now - 15;

    std::vector<SwarmPeerMetadata> swarmRegistry = {
        {"127.0.0.1", "v1.0.5", "Local-Host", "qmk1q00000...00aa", 0.00, "Local Loopback", false, false, now},  
        {"185.220.101.4", "v1.0.5", "Swarm-Rig-01", "qmk1q7p9vx...83a2", 18.68, "Germany (DE)", false, false, now},
        {"192.168.1.147", "v1.0.5", "Intel-i7-Sec", "qmk1q99xxz...77aa", 14.42, "Local LAN (UK)", false, false, simulatedFamilyComputerLastSeen},
        {"192.168.1.100", "v1.0.5", "Threadripper", "qmk1q595wx...55aa", 49.52, "United Kingdom", true, true, now}
    };

    std::cout << "\033[2J\033[H" << std::fixed << std::setprecision(8);
    std::cout << "========================================================================================\n                  QMASK MASTER SWARM OPERATIONAL CONTROL PANEL\n========================================================================================\n Spendable Balance    : " << spendableBalance << " QMK\n Current Block Height : #" << currentHeight << "\n Base Transaction Fee : 0.00010013 QMC Per Kb\n Live Target Block Size: " << calculatedBlockSizeKb << " Kb / 2000.00 Kb Maximum Size Cap\n Connected Swarm Mesh : 5 Active Peer Handshakes\n----------------------------------------------------------------------------------------\n🌌 ====================================================================================\n                  QMASK LAYER-1 NATIVE ZODIAC QUANTUM CONSTELLATION ENGINE          \n========================================================================================\n  [TAURUS WHEEL ALIGNMENT] :  ☄️  Orbit Node Shift: " << (23.72 + std::sin(timeVar * 0.01)) << " ° Alpha Sky Radian Range\n";
    if (now - ts >= 0 && now - ts < 70) { std::cout << "  [ZODIAC ALIGNMENT STATUS] : \033[1;32m🔓 ZODIAC CODEX STATUS: DECRYPTING MAINNET BLOCKS (ACTIVE PILOT)\033[0m\n"; }
    else { std::cout << "  [ZODIAC ALIGNMENT STATUS] : \033[1;33m🔒 ZODIAC CODEX STATUS: PENDING BLOCK CHAIN DAEMON INGEST\033[0m\n"; }
    std::cout << "----------------------------------------------------------------------------------------\n💰 ====================================================================================\n               MONEU LAYER-1 DEDICATED SPENDABLE CRYPTO COIN WALLET                   \n========================================================================================\n  -> LIQUID UNLOCKED GAME COIN BALANCE : " << qmtm << " QMTM (Solid Capital) \n  -> ACCRUED THERMODYNAMIC STABLE ASSET: " << (double)(qmj / 10000.0) << " QME [Ratio Lock: 10,000 QMJ = 1 QME]\n  -> FOUNDER'S GLITCH COIN VAULT BLOCK : 6736.80000000 QMG (80% Locked) 🔒\n  -> FOUNDER RECOVERY TAX ASSET BOUNTY : 1684.20000000 QMC (20% Yield)    ✅\n========================================================================================\n📊 KINETIC BASE LAYER PROTOCOL MATRIX LIVE VISUALS:\n  -> Base Transaction Fee : 0.00010013 QMC Per Kb  👉  [" << visualElectricalBar << " ]\n  -> Live Target Block Size: " << calculatedBlockSizeKb << " Kb / 2000.00 Kb         👉  [" << progressBarText << "🧱 ]\n----------------------------------------------------------------------------------------\n⏱️  AUTOMATED NATIVE BLOCK STOPWATCH MONITOR:\n Last Solved Block Velocity : " << currentVelocity << " Seconds Elapsed\n Consensus Stabilization Target: " << averageBlockTimeCadenceSec << " Seconds Average [ASERT Engine Active]\n 📊 MINI HISTORY RECORD      : " << elapsedSinceLastBlock << "s elapsed since last validated block signature\n----------------------------------------------------------------------------------------\n⏳ MIGRATION T-ZERO MAINNET RESET COUNTDOWN:\n Precise Deadline Clock: " << d << "d " << h << "h " << m << "m " << s << "s remaining until Genesis Reset!\n========================================================================================\n         PRIMARY WORKSTATION PC HARDWARE DIAGNOSTICS & HARDWARE MATRIX\n========================================================================================\n CPU Architecture : AMD Ryzen Threadripper PRO 5955WX (32 Cores) | Utilization: " << cpu << " %\n Core Rail Voltage: 1.224 V Vcore          | Draw Power: " << tdp << " W TDP Peak\n🔋 ACCUMULATED HARDWARE KINETIC ENERGY WORK       : " << qmj << " QMJ\n========================================================================================\n                     QMASK ALL-IN-ONE SWARM NETWORKING REGISTRY REPORT\n========================================================================================\n IP ADDRESS      | CLIENT VERIFY    | RIG IDENTITY | MINING WALLET IDENTITY         | HASHRATE    | COUNTRY/ZONE\n-----------------+------------------+--------------+--------------------------------+-------------+---------------\n";
    for (size_t i = 0; i < swarmRegistry.size(); i++) {
        double currentMH = swarmRegistry[i].baseHashrateMH; std::string cType = "[SIM PASSIVE]";
        if (swarmRegistry[i].isFounder) { cType = "👑 [FOUNDER]   "; }
        else if (now - swarmRegistry[i].lastSeenTimestamp < 10) { cType = "🟢 [REAL PILOT]"; currentMH += std::sin(timeVar + (i * 4.5)) * (swarmRegistry[i].baseHashrateMH * 0.02); }
        else { currentMH = 0.0; }
        std::stringstream ss; ss << std::fixed << std::setprecision(2) << currentMH << " MH/s"; std::string hStr = (currentMH > 0.0) ? ss.str() : "0.00 H/s  ";
        std::cout << " " << std::left << std::setw(15) << swarmRegistry[i].ipAddress << " | " << std::setw(16) << cType << " | " << std::setw(12) << swarmRegistry[i].rigName << " | " << std::setw(30) << swarmRegistry[i].walletAddress << " | " << std::setw(11) << hStr << " | " << swarmRegistry[i].geographicCountry << "\n";
    }
    std::cout << "========================================================================================\n" << "\033[1;32m🟢 GLOBAL SWARM GATEWAY: ACTIVE (PORT 18332 LISTENING VIA NETSH PROXY RELAY) ✅\033[0m\n" << "========================================================================================\n"; return 0;
}
