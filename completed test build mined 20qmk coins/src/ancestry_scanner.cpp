#include <iostream>
#include <string>
#include <map>
#include <iomanip>

struct HistoricalBlock {
    int height;
    double difficulty;
    bool isGpuOrAsicDetected;
};

struct AncestralAccount {
    double historicalBalance;
    bool hasMovedSince2010;
};

class QmaskAncestryScannerEngine {
private:
    const int cpuEraEndBlockHeight = 79000; // Hard boundary cutoff where GPU mining took over history
    double totalRescuedCpuWealth = 0.0;

    std::map<std::string, double> newCpuBitcoinLedgerBalances;

public:
    // 🔍 1. THE TELEMETRY HISTORICAL SCANNER: Audits the birth logs of the parent network
    void ScanHistoricalBlockMetrics(HistoricalBlock block) {
        std::cout << "🔍 [Ancestry Re-Indexer] Auditing Bitcoin Block: #" << block.height << "\n";
        std::cout << "   📊 Difficulty Metric: " << block.difficulty;
        
        if (block.height <= cpuEraEndBlockHeight && !block.isGpuOrAsicDetected) {
            std::cout << " 🟢 [PROFILED AS PURE CPU ERA]\n";
        } else {
            std::cout << " 🔴 [PROFILED AS INDUSTRIAL GPU/ASIC ERA]\n";
        }
    }

    // ⚡ 2. THE PROOF-OF-ANCESTRY FORK FILTER: Rescues early cypherpunks, blocks corporate farms
    void EvaluateAncestralTransfer(const std::string& address, AncestralAccount account, int blockMinedHeight) {
        std::cout << "⚖️  [Ancestry Filter] Checking wallet signature: " << address.substr(0, 18) << "...\n";

        // Hard Filter Logic: Must be mined in CPU era AND remained completely un-moved for 17 years
        if (blockMinedHeight <= cpuEraEndBlockHeight && !account.hasMovedSince2010) {
            newCpuBitcoinLedgerBalances[address] = account.historicalBalance;
            totalRescuedCpuWealth += account.historicalBalance;
            
            std::cout << "👑 [ANCESTRY MATCH] Genuine unmoved 2009 CPU miner verified!\n";
            std::cout << "✨ Action: Successfully transferred +" << account.historicalBalance 
                      << " Coins into your fresh CPU-mined ledger.\n";
        } else {
            newCpuBitcoinLedgerBalances[address] = 0.00; // Erase their balance footprint
            std::cout << "❌ [MINT REJECTED] Wallet flagged as industrial entity, modern whale, or active seller.\n";
            std::cout << "🔒 Balance locked at 0.00000000 on this new ledger lane.\n";
        }
        std::cout << "----------------------------------------------------------------\n\n";
    }
};

int main() {
    std::cout << "🕵️‍♂️ =========================================================\n";
    std::cout << "🕵️‍♂️ INITIALIZING ALPHA-0 PROOF-OF-ANCESTRY SCANNER MACHINE  \n";
    std::cout << "🕵️‍♂️ =========================================================\n\n";

    QmaskAncestryScannerEngine scannerEngine;

    // Simulate scanning two different historical blocks from the parent network
    HistoricalBlock earlyBlock = { 1200, 1.0, false };   // Early 2009 block
    HistoricalBlock modernBlock = { 450000, 999999.0, true }; // Modern ASIC block
    
    scannerEngine.ScanHistoricalBlockMetrics(earlyBlock);
    scannerEngine.ScanHistoricalBlockMetrics(modernBlock);
    std::cout << "\n";

    // CASE A: A legendary 2009 solo CPU miner who hoarded 50 BTC and never sold or moved them
    std::string cypherpunkWallet = "1A1zP1eP5QGefi2DMC_TruePioneerX";
    AncestralAccount cypherpunkAccount = { 50.00, false };
    scannerEngine.EvaluateAncestralTransfer(cypherpunkWallet, cypherpunkAccount, 1200);

    // CASE B: A modern corporate whale or early miner who cashed out their coins long ago
    std::string exchangeWallet = "1ComputerFarms_IndustrialAsicCartel";
    AncestralAccount whaleAccount = { 150000.00, true };
    scannerEngine.EvaluateAncestralTransfer(exchangeWallet, whaleAccount, 82000);

    return 0;
}
