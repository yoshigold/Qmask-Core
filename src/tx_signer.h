#ifndef QMASK_TX_SIGNER_H
#define QMASK_TX_SIGNER_H

#include <string>

class QmaskTxSigner {
public:
    // ✍️ Core function that takes a private seed string and a destination to generate an active signature signature
    std::string GenerateLightweightSignature(const std::string& privateSeed, const std::string& recipientAddress, double amount);
};

#endif // QMASK_TX_SIGNER_H
