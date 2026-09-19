#include "network.h"
#include <iostream>
#include <cmath>
#include <iomanip>

// 🌐 P2P ROUTING HANDSHAKE LOGIC
void QmaskNetworkNode::ConnectToPeer(const std::string& peerIP) {
    connectedPeers.push_back(peerIP);
    std::cout << "[P2P] Linked node peer table entry: " << peerIP << ":" << defaultPort << "\n";
}

// ⚖️ THE THREAD-THROTTLING FAIRNESS ENGINE
double QmaskNetworkNode::CalculateEffectivePower(double rawHardwareThreads) {
    // We run a square root curve to clamp brute-force core scaling
    return std::sqrt(rawHardwareThreads) * 100.0;
}

// 🚀 NETWORK MATRIX TEST BENCH