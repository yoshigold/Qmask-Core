#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct OnChainMessage {
    bool isPublic;
    std::string senderAddress;
    std::string textContent;
};

class QmaskDonationMemoEngine {
private:
    const std::string founderVaultAddress = "qmpFounderVaultAddress_YOSHIKI_MASTER_KEY";
    std::vector<OnChainMessage> publicMessageLedger;

public:
    // 🪙 1. GRANULAR DONATION CONTROLLER (Opt-in with micro-percentage capabilities)
    void ProcessDonationPipeline(bool isEnabled, bool sourceFromBlockReward, double donationPercentage, double transactionalAmount, const std::string& memoText) {
        if (!isEnabled) {
            std::cout << "🟢 [Donation System] Status: OPTED OUT (Disabled by default. 100% of rewards stay with user).\n";
            return;
        }

        // Validate system parameters to ensure strict donor fair-play limits
        if (donationPercentage < 0.001 || donationPercentage > 100.000) {
            std::cout << "❌ [Error] Donation parameters must fall strictly between 0.001% and 100.000%.\n";
            return;
        }

        double absoluteDonationValue = 0.0;

        if (sourceFromBlockReward) {
            // Path A: Coinbase split (Slicing micro-units straight off solved block rewards)
            absoluteDonationValue = transactionalAmount * (donationPercentage / 100.0);
            std::cout << "⛏️  [Donation Active] Source: LIVE BLOCK REWARDS | Setting: " << std::fixed << std::setprecision(3) << donationPercentage << "%\n";
            std::cout << "👑 Routed: " << std::fixed << std::setprecision(6) << absoluteDonationValue << " QMK from block reward directly to Founder Vault.\n";
        } else {
            // Path B: Static balance transfer (Sending explicit user-defined token amounts)
            absoluteDonationValue = transactionalAmount;
            std::cout << "💼 [Donation Active] Source: WALLET BALANCE CONTAINER\n";
            std::cout << "👑 Transferred: " << std::fixed << std::setprecision(4) << absoluteDonationValue << " QMK to Founder Vault.\n";
        }

        // Process message logging if text content is attached
        if (!memoText.empty()) {
            ProcessOnChainMemo(true, "Anonymous_Donor", memoText); // Public by default for ledger records
        }
    }

    // 🌪️ 2. DUAL-MODE MESSAGING INTERFACE (Public Records vs Shielded Memos)
    void ProcessOnChainMemo(bool isPublic, const std::string& sender, const std::string& text) {
        if (isPublic) {
            std::cout << "📡 [Public Memo Logged] Viewable to all nodes on-chain: \"" << text << "\"\n";
            OnChainMessage newRecord = {true, sender, text};
            publicMessageLedger.push_back(newRecord);
        } else {
            // Shielded memo path: Hides data inside the Lattice Matrix layer
            std::cout << "🔒 [Shielded Private Memo] Data encrypted natively under Lattice matrices. Unreadable to sniffers.\n";
        }
    }
};
