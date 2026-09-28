#ifndef QMASK_NETWORK_H
#define QMASK_NETWORK_H

#include <vector>
#include <string>

class QmaskNetworkNode {
private:
    const int defaultPort = 38444; // Dedicated Qmask communication port
    std::vector<std::string> connectedPeers;

public:
    // 🌐 Registers peer nodes onto your local routing table
    void ConnectToPeer(const std::string& peerIP);

    // ⚖️ Calculates a hardware-throttled "Effective Hashrate" to shield older devices
    double CalculateEffectivePower(double rawHardwareThreads);
};

#endif // QMASK_NETWORK_H
