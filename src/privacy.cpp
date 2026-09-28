#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class QmaskPrivacyEngine {
public:
    // 🎛️ FUNCTION: Computes the cryptographic data size footprint of a transaction payload
    int CalculateTxWeight(bool isOptionalPrivacyShielded, int decoyCount) {
        int baseDataSize = 250; // Standard transparent transaction base = 250 bytes

        if (!isOptionalPrivacyShielded) {
            // Standard Transparent Transaction (No privacy layer applied)
            return baseDataSize;
        }

        // Apply our compact Lattice-Based Mimblewimble Masking rules
        // Instead of scaling linearly, decoy weight is compressed mathematically using logarithmic space
        int compactPrivacyShieldWeight = 100 + static_cast<int>(std::log2(decoyCount) * 10);
        
        return baseDataSize + compactPrivacyShieldWeight;
    }
};
