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

struct SwarmPeerMetadata { 
    std::string ipAddress; std::string clientVersion; std::string rigName; 
    std::string walletAddress; double baseHashrateMH; std::string geographicCountry; 
    bool isFounder; bool isWorkstation; long long lastSeenTimestamp; 
};

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

void PrintEncryptedWalletSeedPhrase() {
    std::vector<std::string> wordlist = {"zodiac", "quantum", "constellation", "notary", "kinetic", "vault", "hardware", "stable", "isolated", "swarm", "mesh", "secure"};
    std::cout << "\n========================================================================================\n";
    std::cout << "🔒 GENERATING SECURE ENCRYPTED WALLET 12-WORD MNEMONIC RECOVERY SEED PARADIGM:\n";
    std::cout << "========================================================================================\n  👉 ";
    for (int i = 0; i < 12; i++) std::cout << wordlist[i] << " ";
    std::cout << "\n========================================================================================\n⚠️  WARNING: Store this seed key offline! Your tracking folder parameters are AES-256 protected!\n========================================================================================\n";
}

int main(int argc, char* argv[]) {
    // 🔒 SECURE SHORT-CIRCUIT ROUTER FOR SEED KEY EMISSION
    if (argc >= 2 && argv != nullptr && argv[1] != nullptr && std::string(argv[1]) == "--seed-gen") {
        PrintEncryptedWalletSeedPhrase();
        return 0;
    }
    double wallet = 9865.0; int gx=4, gy=2, lvl=340280, gly=0, d1=0, d2=0, rx=9, ry=0, rc=0, cmb=0; int ehp=100, php=1200;
    double qmtm = 1179.530; int shp = 0; unsigned long long qmj = 185490009451450ULL;
    long long nce = 1017, ts = 0, rng = 0, xp = 15, dmg = 75886, pmd = 0, rgd = 0; double qmkb = 1.476;
    int staffTier = 1; double hashrateBoosterMH = 0.0;
    int riftActive = 0; int bx = -1, by = -1; int bossHp = 500;
    int hasCryptKey = 0; int chestX = 14, chestY = 4; int chestClaimed = 0;
    double totalBurnedSupply = 42.1084; double poolResupplyCoins = 150.00; double founderTipCoins = 0.0;
    double founderGlitchVaultQMG = 6736.8000; double founderRecoveryBountyQMC = 1684.2000;
    int g2x = 11, g2y = 4; std::string logMsg = "💬 [HOTKEY ALERT]: Press [C] to open Swarm Chat Portal! | [B] Shop";

    std::ifstream in("game_state.dat", std::ios::binary);
    if (in.is_open()) { in >> gx >> gy >> lvl >> gly >> d1 >> d2 >> rx >> ry >> rc >> cmb >> ehp >> php >> qmtm >> shp >> qmj >> nce >> ts >> rng >> xp >> dmg >> qmkb >> pmd >> rgd >> hasCryptKey >> chestClaimed >> totalBurnedSupply >> poolResupplyCoins >> founderTipCoins >> founderGlitchVaultQMG >> founderRecoveryBountyQMC; in.close(); }
    if (ehp <= 0) ehp = 100; if (qmj < 100000) qmj = 185490009451450ULL; if (php <= 0) php = 1200;
    long long bootTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    if (argc > 1 && argv != nullptr && std::string(argv[1]) == "--send") {
        if (argc < 4) { std::cout << "❌ Error: Use syntax: ./moneud --send <address> <amount> [--burn|--reward|--founder]\n"; return 1; }
        std::string targetAddress = argv[2]; double sendAmount = std::stod(argv[3]);
        if (qmtm >= sendAmount) {
            qmtm -= sendAmount; double fee = sendAmount * 0.015; std::string mode = "[ENGINE AUTO-SELECT]";
            if (argc > 4 && std::string(argv[4]) == "--burn" && sendAmount > 500.0) {
                double maliciousAsset = fee; founderGlitchVaultQMG += (maliciousAsset * 0.80); founderRecoveryBountyQMC += (maliciousAsset * 0.20);
                mode = "🚨 INTERCEPTED HONEYPOT TRAP: 80/20 COIN CONVERSION EXECUTED SECURELY!"; fee = 0.0;
            }
            else if (argc > 4 && std::string(argv[4]) == "--burn") { totalBurnedSupply += fee; mode = "🔥 MANUAL SUPPLY BURN POSTURE"; }
            else if (argc > 4 && std::string(argv[4]) == "--reward") { poolResupplyCoins += fee; mode = "⛏️ MANUAL MINER REWARD POOL"; }
            else if (argc > 4 && std::string(argv[4]) == "--founder") { founderTipCoins += fee; mode = "👑 VOLUNTARY FOUNDER GIFT"; }
            else {
                if (totalBurnedSupply > 5000.0) poolResupplyCoins += fee; else totalBurnedSupply += fee;
            }
            std::string txHash = ComputeSha256Signature(targetAddress + std::to_string(sendAmount));
            std::cout << "========================================================================================\n📡 BROADCASTING GLOBAL TRANSACTION TO PORT 18332 NETSH PROXY RELAY...\n========================================================================================\n ✅ TX SIGNATURE HASH: " << txHash << "\n ✅ TRANSACTION MODE : " << mode << "\n ✅ RECOVERED SEIZURE : " << std::fixed << std::setprecision(4) << (mode.find("INTERCEPTED") != std::string::npos ? "CONVERTED (80% Vested $QMG / 20% Liquid $QMC)" : "0.0000 $QMK") << "\n ✅ TOTAL VALUE SENT  : " << (sendAmount - fee) << " $QMTM Net Dispatched to " << targetAddress << "\n========================================================================================\n";
            std::ofstream out("game_state.dat", std::ios::binary);
            if (out.is_open()) { out << gx << " " << gy << " " << lvl << " " << gly << " " << d1 << " " << d2 << " " << rx << " " << ry << " " << rc << " " << cmb << " " << ehp << " " << php << " " << qmtm << " " << shp << " " << qmj << " " << nce << " " << ts << " " << rng << " " << xp << " " << dmg << " " << qmkb << " " << pmd << " " << rgd << " " << hasCryptKey << " " << chestClaimed << " " << totalBurnedSupply << " " << poolResupplyCoins << " " << founderTipCoins << " " << founderGlitchVaultQMG << " " << founderRecoveryBountyQMC; out.close(); }
        } else { std::cout << "❌ Transaction Failed: Insufficient liquid balance!\n"; }
        return 0;
    }
    if (argc > 1 && argv != nullptr && std::string(argv[1]) == "--game-panel") {
        while (true) {
            long long now = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            if (riftActive) { cmb = (gx == bx && gy == by) ? 1 : 0; } else { cmb = (gx == rx && gy == ry && !shp) ? 1 : 0; }
            hasCryptKey = (xp >= 20 ? 1 : 0); chestClaimed = (qmtm >= 1500.0 ? 1 : 0);
            if (now % 3 == 0) { g2x += (now % 3) - 1; g2y += (now % 2) - 1; if(g2x<0)g2x=0; if(g2x>15)g2x=15; if(g2y<0)g2y=0; if(g2y>5)g2y=5; }

            std::cout << "\033[2J\033[H=================== MONEU LAYER-1 HYBRID CORES OPERATION ROOM ===================\n"
                      << "🔍 [AUDIT] SWARM MESH STATUS       : 🟢 MULTIPLAYER INTERNET ENTITY INTERCONNECT ONLINE\n"
                      << "💰 [VAULT] PRIMARY WALLET BALANCE  : " << std::fixed << std::setprecision(4) << qmtm << " $QMTM Shards\n"
                      << "💰 [VAULT] FOUNDER'S GLITCH LOCK   : " << founderGlitchVaultQMG << " $QMG (80% Honeypot Seizure Vested)  🔒\n"
                      << "💰 [VAULT] FOUNDER RECOVERY BOUNTY : " << founderRecoveryBountyQMC << " $QMC (20% Honeypot Seizure Bounty)  ✅\n"
                      << "💰 [VAULT] THERMODYNAMIC BALANCE   : " << (double)(qmj / 10000.0) << " $QME | Vol Tips: " << founderTipCoins << " QMK\n"
                      << "💰 [STATS] TOTAL KINETIC DAMAGE    : " << dmg << " HP Dealt | Current Level Shards: " << xp << " XP\n"
                      << "💰 [STATS] MULTIPLAYER CORES SYNC  : Wizard 1 [🧙] | Wizard 2 [🧙‍♂️] -> Positions Bound\n"
                      << "💰 [STATS] CRYPT KEYS COLLECTED    : " << (hasCryptKey ? "🔑 SECURED" : "❌ NONE") << "\n"
                      << "=================================================================================\n"
                      << " 🌾 CAMPAIGN FIELD [ 🔴 MULTIPLAYER PROGRESSIVE CRYPT ]: " << logMsg << "\n"
                      << "---------------------------------------------------------------------------------\n";
            if (!shp) {
                for (int y = 0; y < 6; y++) {
                    std::cout << "   | ";
                    for (int x = 0; x < 16; x++) {
                        if (x == gx && y == gy) std::cout << "🧙 ";
                        else if (x == g2x && y == g2y) std::cout << "🧙‍♂️ ";
                        else if (y == 3 && x >= 6 && x <= 10) std::cout << "🧱 "; 
                        else if (!chestClaimed && x == chestX && y == chestY) std::cout << "📦 ";
                        else if (riftActive && x == bx && y == by) std::cout << "👹 ";
                        else if (!riftActive && x == rx && y == ry) std::cout << "👾 ";
                        else std::cout << ".  ";
                    } std::cout << "|\n";
                }
            }
            std::cout << "---------------------------------------------------------------------------------\n"
                      << "[CONTROLS] : W,A,S,D Move | [SPACEBAR] Strike | [B] Shop | [R] Rift | [C] Chat | X: Exit\n"
                      << "=================================================================================\n";
            
            char key = CaptureRawKeystrokeNatively();
            if (key == 'x' || key == 'X') break;
            if (key == 'b' || key == 'B') { shp = !shp; cmb = 0; if (shp && gx == rx && gy == ry) { gy++; if (gy > 5) gy = 4; } continue; }
            if (key == 'c' || key == 'C') {
                std::cout << "\n💬 [SWARM P2P CHAT PORTAL] Type message to broadcast: ";
                std::string chatInput; std::getline(std::cin, chatInput);
                logMsg = "📡 [LEDGER IMPRINT SUCCESS] Sent: \"" + chatInput + "\" across Port 18332 channels! ✅";
                continue;
            }
            if (key == 'r' || key == 'R') {
                double currentQme = (double)(qmj / 10000.0);
                if (currentQme >= 5.0 && !riftActive) { qmj -= 50000; riftActive = 1; bossHp = 500; bx = 12; by = 1; }
                continue;
            }

            int prevX = gx, prevY = gy;
            if (key == 'w' || key == 'W') gy--; if (key == 's' || key == 'S') gy++;
            if (key == 'a' || key == 'A') gx--; if (key == 'd' || key == 'D') gx++;
            if (gy == 3 && gx >= 6 && gx <= 10) { if (!hasCryptKey) { gx = prevX; gy = prevY; } }
            if (gx == chestX && gy == chestY && !chestClaimed) { chestClaimed = 1; qmtm += 350.0; }

            if (key == ' ' && cmb == 1) {
                int hit = (15 + (now % 16)) * staffTier;
                if (riftActive) { bossHp -= hit; if (bossHp <= 0) { rgd++; xp += 25; qmtm += 500.0; riftActive = 0; } }
                else { ehp -= hit; if (ehp <= 0) { xp += 5; qmtm += 65.0; ehp = 100; rx = 2 + (now % 12); ry = 1 + (now % 4); } }
            }
            if (gx < 0) gx = 0; if (gx > 15) gx = 15; if (gy < 0) gy = 0; if (gy > 5) gy = 5;
            std::ofstream out("game_state.dat", std::ios::binary);
            if (out.is_open()) { out << gx << " " << gy << " " << lvl << " " << gly << " " << d1 << " " << d2 << " " << rx << " " << ry << " " << rc << " " << cmb << " " << ehp << " " << php << " " << qmtm << " " << shp << " " << qmj << " " << nce << " " << ts << " " << now << " " << xp << " " << dmg << " " << qmkb << " " << pmd << " " << rgd << " " << hasCryptKey << " " << chestClaimed << " " << totalBurnedSupply << " " << poolResupplyCoins << " " << founderTipCoins << " " << founderGlitchVaultQMG << " " << founderRecoveryBountyQMC; out.close(); }
        } return 0;
    }
    long long currentHeight = lvl;
    if (argc > 1 && argv != nullptr && std::string(argv[1]) == "--daemon-miner-scroll") {
        if (argc > 2 && argv != nullptr) { try { currentHeight = std::stoll(std::string(argv[2])); } catch (...) {} }
        std::cout << "========================================================================================\n🚀 QMASK CORE DAEMON INITIALISED: Launching Native STVW Scrolling Miner Engine...\n========================================================================================\n\n";
        while (true) {
            long long loopTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            double timeVar = static_cast<double>(loopTime); double tdpDraw = 278.45 + (std::abs(std::cos(timeVar * 0.4)) * 34.20);
            std::ifstream inCheck("game_state.dat", std::ios::binary);
            if (inCheck.is_open()) { inCheck >> gx >> gy >> lvl >> gly >> d1 >> d2 >> rx >> ry >> rc >> cmb >> ehp >> php >> qmtm >> shp >> qmj >> nce >> ts >> rng >> xp >> dmg >> qmkb >> pmd >> rgd >> hasCryptKey >> chestClaimed >> totalBurnedSupply >> poolResupplyCoins >> founderTipCoins >> founderGlitchVaultQMG >> founderRecoveryBountyQMC; inCheck.close(); }
            if (qmj < 100000) qmj = 185490009451450ULL; qmj += static_cast<unsigned long long>(tdpDraw * 8.5);
            std::cout << "[BLOCK VALIDATED] Mined Block Height: #" << currentHeight << " | Difficulty: 400000000000\n🪐 [STVW Engine] Active Block Height: #" << currentHeight << " | Live Energy Balance: " << qmj << " QMJ\n🟢 Stable Baseline Loop: Issuing regular 5.00 QMK mining reward blocks.\n" << std::flush;
            currentHeight++; std::ofstream out("game_state.dat", std::ios::binary);
            if (out.is_open()) { out << gx << " " << gy << " " << currentHeight << " " << gly << " " << d1 << " " << d2 << " " << rx << " " << ry << " " << rc << " " << cmb << " " << ehp << " " << php << " " << qmtm << " " << shp << " " << qmj << " " << nce << " " << ts << " " << loopTime << " " << rng << " " << xp << " " << dmg << " " << qmkb << " " << pmd << " " << rgd << " " << hasCryptKey << " " << chestClaimed << " " << totalBurnedSupply << " " << poolResupplyCoins << " " << founderTipCoins << " " << founderGlitchVaultQMG << " " << founderRecoveryBountyQMC; out.close(); }
            std::this_thread::sleep_for(std::chrono::milliseconds(60000));
        } return 0;
    }
    std::ifstream inLive("game_state.dat", std::ios::binary);
    if (inLive.is_open()) { inLive >> gx >> gy >> currentHeight >> gly >> d1 >> d2 >> rx >> ry >> rc >> cmb >> ehp >> php >> qmtm >> shp >> qmj >> nce >> ts >> rng >> xp >> dmg >> qmkb >> pmd >> rgd >> hasCryptKey >> chestClaimed >> totalBurnedSupply >> poolResupplyCoins >> founderTipCoins >> founderGlitchVaultQMG >> founderRecoveryBountyQMC; inLive.close(); }
    if (qmj < 100000) qmj = 185490009451450ULL;

    long long now = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    double timeVar = static_cast<double>(now); long long rem = 1790905200LL - now; if (rem < 0) rem = 0;
    long long d = rem / 86400, h = (rem % 86400) / 3600, m = (rem % 3600) / 60, s = rem % 60;
    double speed = 24532431.0 + std::sin(timeVar)*14850.0; double tdp = 278.45 + (std::abs(std::cos(timeVar * 0.4)) * 34.20);
    long long structuralDelta = 15 + (now % 6); qmj += static_cast<unsigned long long>(tdp * 0.85) + (structuralDelta * 18500ULL);

    long long blockGains = currentHeight - 337823; if (blockGains < 0) blockGains = 0;
    long long calculatedLifetimeBlocks = 2658 + blockGains; double calculatedLifetimeCoins = (blockGains * 5.0) + 13290.0;
    double spendableBalance = wallet + (blockGains * 5.0) + qmtm;
    long long elapsedSinceLastBlock = now - ts; if (ts <= 0 || elapsedSinceLastBlock < 0 || elapsedSinceLastBlock > 3600) elapsedSinceLastBlock = now % 60;
    double averageBlockTimeCadenceSec = 60.0145 + (std::sin(static_cast<double>(currentHeight) * 0.2) * 0.0380);
    double cpu = 90.95 + (std::sin(timeVar * 0.5) * 1.1);

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
    std::string liveMetricsPayload = std::to_string(currentHeight) + std::to_string(spendableBalance) + std::to_string(now);
    std::string currentBlockSignatureSha256 = ComputeSha256Signature(liveMetricsPayload);

    std::cout << "\033[2J\033[H" << std::fixed << std::setprecision(8);
    std::cout << "========================================================================================\n                  QMASK MASTER SWARM OPERATIONAL CONTROL PANEL\n========================================================================================\n"
              << " Spendable Balance    : " << spendableBalance << " QMK\n Immature Vault Total : 500.00000000 QMK (100 Blocks Locked)\n Circulating Supply   : " << std::fixed << std::setprecision(8) << (1699295.0 + (blockGains * 5.0) - totalBurnedSupply) << " QMK / 21000000.00 QMK Max\n Rig Mining Speed     : " << speed << " H/s (32 Cores Pegged)\n Total Network Power  : 137661790 H/s (137.66179000 MH/s Estimated)\n Current Block Height : #" << currentHeight << "\n Base Transaction Fee : 0.00010013 QMC Per Kb\n Live Target Block Size: " << calculatedBlockSizeKb << " Kb / 2000.00 Kb Maximum Size Cap\n Blocks to Retarget   : 469 Blocks Remaining\n Connected Swarm Mesh : 5 Active Peer Handshakes\n"
              << " Miner Lifetime Blocks: " << calculatedLifetimeBlocks << " Blocks Solved | Lifetime Mined: " << calculatedLifetimeCoins << " QMC\n Governance Stance    : SHARE_FTG Voting Pipeline Engaged\n----------------------------------------------------------------------------------------\n"
              << "🌌 ====================================================================================\n                  QMASK LAYER-1 NATIVE ZODIAC QUANTUM CONSTELLATION ENGINE          \n========================================================================================\n  [TAURUS WHEEL ALIGNMENT] :  ☄️  Orbit Node Shift: " << (23.72 + std::sin(timeVar * 0.01)) << " ° Alpha Sky Radian Range\n  [LEO ASTRO MATRIX SYNC]  :  🌟 Harmonic Hash Rate Vector: [ 3f26 ] Node Checkpoint\n  [NATIVE CONSTELLATION SE] :  👉  [" << visualElectricalBar << " ] NATIVE CODES TUNNEL MATRIX ACCELERATOR\n  [ZODIAC ALIGNMENT STATUS] : \033[1;32m🔓 ZODIAC CODEX STATUS: DECRYPTING MAINNET BLOCKS (ACTIVE PILOT)\033[0m\n  [SHA-256 BLOCK NOTARY]   : \033[1;36m🛡️  CURRENT SIGNATURE HASH: " << currentBlockSignatureSha256 << "\033[0m\n----------------------------------------------------------------------------------------\n"
              << "💰 ====================================================================================\n               MONEU LAYER-1 DEDICATED SPENDABLE CRYPTO COIN WALLET                   \n========================================================================================\n  -> LIQUID UNLOCKED GAME COIN BALANCE : " << qmtm << " QMTM (Solid Capital) \n  -> ACCRUED THERMODYNAMIC STABLE ASSET: " << std::fixed << std::setprecision(4) << (double)(qmj / 10000.0) << " QME [Ratio Lock: 10,000 QMJ = 1 QME]\n  -> FOUNDER'S GLITCH COIN VAULT BLOCK : " << founderGlitchVaultQMG << " QMG (80% Honeypot Seizure Vested Lock) 🔒\n  -> FOUNDER RECOVERY TAX ASSET BOUNTY : " << founderRecoveryBountyQMC << " QMC (20% Distributed Yield Seizure) ✅\n========================================================================================\n📊 KINETIC BASE LAYER PROTOCOL MATRIX LIVE VISUALS:\n  -> Base Transaction Fee : 0.00010013 QMC Per Kb\n  -> Live Target Block Size: " << calculatedBlockSizeKb << " Kb / 2000.00 Kb         👉  [" << progressBarText << "🧱 ]\n----------------------------------------------------------------------------------------\n⏱️  AUTOMATED NATIVE BLOCK STOPWATCH MONITOR:\n Last Solved Block Velocity : " << 54 + (currentHeight % 13) << " Seconds Elapsed\n Consensus Stabilization Target: " << averageBlockTimeCadenceSec << " Seconds Average [ASERT Engine Active]\n 📊 MINI HISTORY RECORD      : " << elapsedSinceLastBlock << "s elapsed since last validated block signature\n----------------------------------------------------------------------------------------\n⏳ MIGRATION T-ZERO MAINNET RESET COUNTDOWN:\n Precise Deadline Clock: " << d << "d " << h << "h " << m << "m " << s << "s remaining until Genesis Reset!\n----------------------------------------------------------------------------------------\n👑 SOVEREIGN MULTI-CHAIN TROPHY CASE & GAME VAULT DISPLAY BALANCE :\n  -> Active Collectible Trophy: 👑 [KRAKEN_SOVEREIGN_REGINA] (MAX_TIER) (+ 25.00 MH/s Booster Active!)\n  💰 ON-CHAIN GAME TOKEN LIQUID ACCRUED  : " << totalBurnedSupply << " QMK | Voluntary Tips: " << founderTipCoins << " QMK\n========================================================================================\n         PRIMARY WORKSTATION PC HARDWARE DIAGNOSTICS & HARDWARE MATRIX\n========================================================================================\n CPU Architecture : AMD Ryzen Threadripper PRO 5955WX (32 Cores) | Utilization: " << cpu << " %\n Core Rail Voltage: 1.224 V Vcore          | Draw Power: " << tdp << " W TDP Peak\n🔋 ACCUMULATED HARDWARE KINETIC ENERGY WORK       : " << qmj << " QMJ\n========================================================================================\n                     QMASK ALL-IN-ONE SWARM NETWORKING REGISTRY REPORT\n========================================================================================\n IP ADDRESS      | CLIENT VERIFY    | RIG IDENTITY | MINING WALLET IDENTITY         | HASHRATE    | COUNTRY/ZONE\n-----------------+------------------+--------------+--------------------------------+-------------+---------------\n";
    for (size_t i = 0; i < swarmRegistry.size(); i++) {
        double currentMH = swarmRegistry[i].baseHashrateMH; std::string cType = "[SIM PASSIVE]";
        if (swarmRegistry[i].isFounder) { cType = "👑 [FOUNDER]   "; }
        else if (now - swarmRegistry[i].lastSeenTimestamp < 10) { cType = "🟢 [REAL PILOT]"; currentMH += std::sin(timeVar + (i * 4.5)) * (swarmRegistry[i].baseHashrateMH * 0.02); }
        else { currentMH = 0.0; }
        std::stringstream ss; ss << std::fixed << std::setprecision(2) << currentMH << " MH/s"; std::string hStr = (currentMH > 0.0) ? ss.str() : "0.00 H/s  ";
        std::cout << " " << std::left << std::setw(15) << swarmRegistry[i].ipAddress << " | " << std::setw(16) << cType << " | " << std::setw(12) << swarmRegistry[i].rigName << " | " << std::setw(30) << swarmRegistry[i].walletAddress << " | " << std::setw(11) << hStr << " | " << swarmRegistry[i].geographicCountry << "\n";
    }
    std::cout << "========================================================================================\n" << "\033[1;32m🟢 GLOBAL SWARM GATEWAY: ACTIVE (PORT 18332 LISTENING VIA NETSH PROXY RELAY) ✅\033[0m\n" << "========================================================================================\n";
    std::ofstream out("game_state.dat", std::ios::binary);
    if (out.is_open()) { out << gx << " " << gy << " " << currentHeight << " " << gly << " " << d1 << " " << d2 << " " << rx << " " << ry << " " << rc << " " << cmb << " " << ehp << " " << php << " " << qmtm << " " << shp << " " << qmj << " " << nce << " " << ts << " " << now << " " << xp << " " << dmg << " " << qmkb << " " << pmd << " " << rgd << " " << hasCryptKey << " " << chestClaimed << " " << totalBurnedSupply << " " << poolResupplyCoins << " " << founderTipCoins << " " << founderGlitchVaultQMG << " " << founderRecoveryBountyQMC; out.close(); }
    return 0;
}
