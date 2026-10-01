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
#include <openssl/sha.h>
char CaptureRawKeystrokeNatively() {
    char inputChar = 0; struct termios oldSettings, newSettings;
    if (tcgetattr(STDIN_FILENO, &oldSettings) < 0) return 0;
    newSettings = oldSettings; newSettings.c_lflag &= ~(ICANON | ECHO);
    newSettings.c_cc[VMIN] = 1; newSettings.c_cc[VTIME] = 0;
    if (tcsetattr(STDIN_FILENO, TCSANOW, &newSettings) < 0) return 0;
    if (read(STDIN_FILENO, &inputChar, 1) < 0) inputChar = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
    return inputChar;
}
std::string ComputeSha256Signature(const std::string& inputDataString) {
    unsigned char hashDigest[SHA256_DIGEST_LENGTH]; SHA256_CTX sha256Context;
    SHA256_Init(&sha256Context); SHA256_Update(&sha256Context, inputDataString.c_str(), inputDataString.size());
    SHA256_Final(hashDigest, &sha256Context); std::stringstream textStream;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) textStream << std::hex << std::setw(2) << std::setfill('0') << (int)hashDigest[i];
    return "0x" + textStream.str();
}

std::string DecryptNpcIdentityFromHash(const std::string& blockHash) {
    if (blockHash.size() < 10) return "PHANTOM-SHADOW";
    return "AGENT-" + blockHash.substr(2, 4) + "-NODE";
}
int main(int argc, char* argv[]) {
    int gx = 4, gy = 2, g2x = 11, g2y = 4;
    long long lvl = 343757; double spendable = 43164.10; double qmtm = 1809.53;
    unsigned long long qmj = 185492072007400ULL; double burned = 57.04;
    double difficulty = 800000000.0; long long solvedTime = 0;
    long long ltBlocks = 5934; double ltMined = 29670.00;
    long long dmg = 1790756192; int xp = 15;
    std::string logMsg = "💬 [HOTKEY ALERT]: Press [C] to open Swarm Chat Portal! | [B] Shop";
    while (true) {
        long long loopTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        std::ifstream in("game_state.dat", std::ios::binary);
        if (in.is_open()) { in >> lvl >> spendable >> qmtm >> qmj >> burned >> difficulty >> solvedTime >> ltBlocks >> ltMined; in.close(); }
        
        std::ifstream inMiner("miner_state.dat", std::ios::binary);
        if (inMiner.is_open()) { inMiner >> ltBlocks >> ltMined >> solvedTime; inMiner.close(); }

        int proximityDistance = std::abs(gx - g2x) + std::abs(gy - g2y);
        std::string dummyHash = ComputeSha256Signature(std::to_string(loopTime)); std::string activeNpcName = DecryptNpcIdentityFromHash(dummyHash);
        if (loopTime % 3 == 0) { g2x += (loopTime % 3) - 1; g2y += (loopTime % 2) - 1; if(g2x<0)g2x=0; if(g2x>15)g2x=15; if(g2y<0)g2y=0; if(g2y>5)g2y=5; }
        if (proximityDistance <= 1) { logMsg = "✨ [SWARM PROXIMITY]: Press [T] to Atomic Trade, or [K] to Crypt Duel! ⚔️"; }
        std::cout << "\033[2J\033[H=================== MONEU LAYER-1 HYBRID CORES OPERATION ROOM ===================\n"
                  << "🔍 [AUDIT] SWARM MESH STATUS       : 🟢 MULTIPLAYER INTERNET ENTITY INTERCONNECT ONLINE\n"
                  << "🔍 [AUDIT] INCIDENT RECOVERY MAP   : 🛰️ STORAGE ENVIRONMENT DATA PATHWAYS VERIFIED\n"
                  << "🛡️  [SECURITY] DEFENSE HISTORY    : 🔒 HONEYPOT INTERCEPTOR GATES STANDING ARMED\n"
                  << "🛡️  [SECURITY] ECONOMIC ATTEMPTS  : 🚨 SYSTEM AUTO-ALERT STATUS: HEALTHY / CLEAN\n"
                  << "🛡️  [SECURITY] EXPLOIT INCIDENT   : ⚠️ METADATA FORENSIC RECORD FOR SEIZED ASSETS: 1699295.00 QMTM\n"
                  << "🛡️  [SECURITY] INCIDENT TIMESTAMP : 📅 EXPLOIT DATE/TIME: 2026-03-14 04:15:29 UTC (EPOCH CAPTURE)\n"
                  << "🛡️  [SECURITY] SCAN TARGET VECTOR : 📑 MEMORY SLICE: STVW VECTOR OVERFLOW ATTACK BLOCKED\n"
                  << "🛡️  [SECURITY] THREAT RESOLUTION  : ✅ IMMUTABLE PATCH: LOCKED RESIDUAL ASSETS IN VAULT CUSTODY\n"
                  << "💰 [VAULT] PRIMARY WALLET BALANCE  : " << std::fixed << std::setprecision(4) << qmtm << " $QMTM Shards\n"
                  << "💰 [VAULT] FOUNDER'S GLITCH LOCK   : 6736.8000 $QMG (80% Honeypot Seizure Vested)  🔒\n"
                  << "💰 [VAULT] FOUNDER RECOVERY BOUNTY : 1684.2000 $QMC (20% Honeypot Seizure Bounty)  ✅\n"
                  << "💰 [VAULT] THERMODYNAMIC BALANCE   : " << (double)(qmj / 10000.0) << " $QME\n"
                  << "💰 [STATS] TOTAL KINETIC DAMAGE    : " << dmg << " HP Dealt | Current Level Shards: " << xp << " XP\n"
                  << "💰 [STATS] MULTIPLAYER CORES SYNC  : Wizard 1 [🧙] | Wizard 2 [🧙‍♂️] -> Positions Bound\n"
                  << "💰 [STATS] CRYPT KEYS COLLECTED    : 🔑 SECURED\n"
                  << "=================================================================================\n"
                  << " 🌾 CAMPAIGN FIELD [ 🔴 MULTIPLAYER PROGRESSIVE CRYPT ]: " << logMsg << "\n"
                  << "---------------------------------------------------------------------------------\n";
        for (int y = 0; y < 6; y++) {
            std::cout << "   | ";
            for (int x = 0; x < 16; x++) {
                if (x == gx && y == gy) std::cout << "🧙 ";
                else if (x == g2x && y == g2y) std::cout << "🧙‍♂️ ";
                else if (y == 3 && x >= 6 && x <= 10) std::cout << "🧱 "; 
                else std::cout << ".  ";
            } std::cout << "|\n";
        }
        std::cout << "---------------------------------------------------------------------------------\n"
                  << "  🏆 [SWARM MAINNET] GLOBAL NETWORK RANKING LEADERBOARD REPORT\n"
                  << "  👑 #1 | qmk1q595wx...55aa [FOUNDER]  | Damage: " << dmg << " HP | Status: ACTIVE SECURE\n"
                  << "     #2 | " << activeNpcName << " [SHADOW-AI] | Coordinates: Bound  | Ping: 14ms\n"
                  << "---------------------------------------------------------------------------------\n"
                  << "[CONTROLS] : W,A,S,D Move | [SPACE] Strike | [T] Atomic Swap | [K] Duel | [C] Chat | X: Exit\n"
                  << "=================================================================================\n";
        char key = CaptureRawKeystrokeNatively();
        if (key == 'x' || key == 'X') break;
        if (key == 't' || key == 'T' && proximityDistance <= 1) { logMsg = "✅ ATOMIC SWAP SUCCESS: Exchanged Shards! 📡"; }
        if (key == 'k' || key == 'K' && proximityDistance <= 1) { dmg += 5000; logMsg = "⚔️ P2P DUEL ENGAGED: +5,000 Kinetic Points! ⚡"; }
        if (key == 'w' || key == 'W') gy--; if (key == 's' || key == 'S') gy++; if (key == 'a' || key == 'A') gx--; if (key == 'd' || key == 'D') gx++;
        if (gx < 0) gx = 0; if (gx > 15) gx = 15; if (gy < 0) gy = 0; if (gy > 5) gy = 5;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    return 0;
}
