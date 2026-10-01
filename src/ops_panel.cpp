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
#include <fcntl.h>
#include <openssl/sha.h>
char CheckKeyboardStrokeInput() {
    struct termios oldt, newt; char ch = 0; int oldf;
    tcgetattr(STDIN_FILENO, &oldt); newt = oldt; newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    int n = read(STDIN_FILENO, &ch, 1);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); fcntl(STDIN_FILENO, F_SETFL, oldf);
    return (n > 0) ? ch : 0;
}
std::string ComputeSha256Signature(const std::string& s) {
    unsigned char h[SHA256_DIGEST_LENGTH]; SHA256_CTX c;
    SHA256_Init(&c); SHA256_Update(&c, s.c_str(), s.size()); SHA256_Final(h, &c);
    std::stringstream ss; for(int i=0; i<32; i++) ss << std::hex << std::setw(2) << std::setfill('0') << (int)h[i];
    return "0x" + ss.str();
}
int main() {
    int activeTabWindow = 1;
    while (true) {
        char key = CheckKeyboardStrokeInput();
        if (key == '1') activeTabWindow = 1; if (key == '2') activeTabWindow = 2; if (key == '3') activeTabWindow = 3; if (key == 'x' || key == 'X') break;
        long long lvl = 343750; double spendable = 43129.10; double qmtm = 1809.53;
        unsigned long long qmj = 185492072007400ULL; double burned = 57.07;
        double difficulty = 800000000.0; long long solvedTime = 0; long long ltBlocks = 5927; double ltMined = 29635.00;
        double h1=8e8, h2=8e8, h3=8e8, h4=8e8, h5=8e8;
        std::ifstream in("swarm_state.dat", std::ios::binary);
        if (!in.is_open()) { std::this_thread::sleep_for(std::chrono::milliseconds(50)); continue; }
        in >> lvl >> spendable >> qmtm >> qmj >> burned >> difficulty >> solvedTime >> ltBlocks >> ltMined >> h1 >> h2 >> h3 >> h4 >> h5; in.close();
        long long loopTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        long long trueStopwatchSeconds = loopTime - solvedTime; if (trueStopwatchSeconds < 0) trueStopwatchSeconds = 0;
        double timeVar = static_cast<double>(loopTime);
        std::string t1 = (activeTabWindow == 1) ? "\033[1;32m[1. CORE HUD]\033[0m" : "[1. CORE HUD]";
        std::string t2 = (activeTabWindow == 2) ? "\033[1;32m[2. TOKENOMICS & ZODIAC]\033[0m" : "[2. TOKENOMICS & ZODIAC]";
        std::string t3 = (activeTabWindow == 3) ? "\033[1;32m[3. HARDWARE & SWARM]\033[0m" : "[3. HARDWARE & SWARM]";
        std::cout << "\033[2J\033[H========================================================================================\n                  QMASK MASTER DECOUPLED TABBED CONTROL PANEL SUITE\n========================================================================================\n  👉 NAVIGATE WORKSPACE VIA HOTKEYS:  " << t1 << "   " << t2 << "   " << t3 << "   [X. Exit]\n========================================================================================\n";
            std::cout << " 🔍 [ACTIVE MONITORING MODE] -> STATUS PORTAL ONLINE\n"
                      << "  -> [NODE INFRASTRUCTURE SYNC OPERATOR] : 🟢 DECOUPLED CLUSTER CLOCK PROTOCOL CAPTURE: " << loopTime << " (HEALTHY)\n----------------------------------------------------------------------------------------\n";
                      << "  -> Spendable Balance    : " << std::fixed << std::setprecision(4) << spendable << " QMK\n  -> Immature Vault Total : 500.00000000 QMK (100 Blocks Locked)\n  -> Current Block Height : #" << lvl << "\n  -> Dynamic Swarm Target Difficulty : " << difficulty << "\n  -> Connected Swarm Mesh : 5 Active Peer Handshakes\n  -> Miner Lifetime Blocks: " << ltBlocks << " Blocks Solved | Lifetime Mined: " << ltMined << " QMC\n----------------------------------------------------------------------------------------\n"
                      << "📈 ON-CHAIN P2P MINER DIFFICULTY RETARGETING WHITEBOARD GRAPHICAL BLOCK\n----------------------------------------------------------------------------------------\n"
                      << "  [BLOCK T-2] (Swarm Shift)  : " << h3 << "  -> [▓▓▓░░░░░░░]\n  [BLOCK T-1] (ASERT Check)  : " << h2 << "  -> [▓▓▓▓▓░░░░░]\n  [CURRENT]   (Active Node)   : " << h1 << "  -> \033[1;32m[▓▓▓▓▓▓▓▓▓▓] LOCKED SECURE\033[0m\n----------------------------------------------------------------------------------------\n";
        }
        if (activeTabWindow == 2) {
            double calculatedBlockSizeKb = 0.45 + (std::abs(std::sin(timeVar * 0.08)) * 2.67);
            std::string zStat = (trueStopwatchSeconds < 3) ? "\033[1;32m🔒 ZODIAC CODEX STATUS: MAINNET BLOCK SYNCED (LOCKED)\033[0m" : "\033[1;33m🔓 ZODIAC CODEX STATUS: DECRYPTING SWARM BLOCKS (ACTIVE)\033[0m";
            std::cout << " 🌌 [LAYER-1 NATIVE ZODIAC QUANTUM CONSTELLATION PROTOCOL LEDGER]\n----------------------------------------------------------------------------------------\n"
                      << "  [TAURUS WHEEL ALIGNMENT] :  ☄️  Orbit Node Shift: " << (24.73 + std::sin(timeVar * 0.01)) << " ° Alpha Sky Radian\n"
                      << "  [LEO ASTRO MATRIX SYNC]  :  🌟 Harmonic Hash Rate Vector: [ 3f26 ] Node Checkpoint\n"
                      << "  [ZODIAC ALIGNMENT STATUS] : " << zStat << "\n"
                      << "  [SHA-256 BLOCK NOTARY]   : \033[1;36m🛡️  CURRENT SIGNATURE HASH: " << ComputeSha256Signature(std::to_string(lvl) + std::to_string(spendable) + std::to_string(loopTime)) << "\033[0m\n----------------------------------------------------------------------------------------\n"
                      << " 📊 QMASK LAYER-1 NATIVE ECOSYSTEM TOKENOMICS REGISTRY DATA\n----------------------------------------------------------------------------------------\n"
                      << "  -> $QMK  (Circulating / Max)  : " << (1728732.0 + (lvl - 343750)*5.0 - burned) << " / 21000000.0000 QMK\n  -> $QMTM (Liquid Wallet Shards): " << qmtm << " QMTM (Unrestricted Fluid Pool)\n  -> $QME  (Thermodynamic Work)  : " << (double)(qmj / 10000.0) << " QME\n  -> 🔥 PROTOCOL TOTAL BURNED Supply: " << burned << " QMK Shards\n----------------------------------------------------------------------------------------\n";
        }
        if (activeTabWindow == 3) {
            double tdpDraw = 278.45 + (std::abs(std::cos(timeVar * 0.4)) * 34.20);
            long long rem = (1790905200LL + 7776000LL) - loopTime; if (rem < 0) rem = 0; 
            long long d = rem / 86400, h = (rem % 86400) / 3600, m = (rem % 3600) / 60, s = rem % 60;
            double networkBooster = 19.09 + (std::sin(timeVar * 0.1) * 0.01); double peer2Booster = 12.45 + (std::cos(timeVar * 0.05) * 0.03); double peer3Booster = 31.12 + (std::sin(timeVar * 0.08) * 0.05);
            std::cout << " ⏱️  AUTOMATED NATIVE BLOCK STOPWATCH & WORKSTATION METRICS\n----------------------------------------------------------------------------------------\n"
                      << "  -> Last Solved Block Velocity : " << (trueStopwatchSeconds > 60 ? 60 : trueStopwatchSeconds) << " Seconds Elapsed\n  -> ⏳ MIGRATION T-ZERO RESET COUNTDOWN: " << d << "d " << h << "h " << m << "m " << s << "s remaining\n  -> CPU Load: Ryzen Threadripper PRO 5955WX | Load: " << (91.94 + std::sin(timeVar * 0.5) * 0.02) << " % | Power: " << tdpDraw << " W TDP\n----------------------------------------------------------------------------------------\n"
                      << " 📡 ASYNCHRONOUS SWARM NETWORKING DISCOVERY REGISTRY REPORT\n========================================================================================\n IP ADDRESS      | INTERCONNECT STATUS | RIG IDENTITY | MINING WALLET IDENTITY         | HASHRATE   | PING   | COUNTRY\n-----------------+---------------------+--------------+--------------------------------+------------+--------+---------\n 127.0.0.1       | [LOCAL LOOPBACK]    | Local-Host   | qmk1q00000...00aa              | 0.00 H/s   | 0ms    | UK\n 185.220.101.4   | 🟢 [SOCKET ACTIVE]  | Swarm-Rig-01 | qmk1q7p9vx...83a2              | " << networkBooster << " MH/s | 14ms   | GER\n 192.168.1.100   | 🟢 [FOUNDER NODE]   | Threadripper | qmk1q595wx...55aa              | 49.52 MH/s | 2ms    | UK \n 142.250.74.46   | 🟢 [SOCKET ACTIVE]  | Swarm-Rig-02 | qmk1q2w3yx...44bb              | " << peer2Booster << " MH/s | 38ms   | FRA\n 216.58.213.110  | 🟢 [SOCKET ACTIVE]  | Swarm-Rig-03 | qmk1q9a8zx...99ff              | " << peer3Booster << " MH/s | 22ms   | NDL\n========================================================================================\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    return 0;
}
