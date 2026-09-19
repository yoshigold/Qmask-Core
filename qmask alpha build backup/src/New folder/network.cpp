#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class QmaskNetworkNode {
public:
    // Core P2P networking variables
    const int defaultPort = 38444; // Dedicated Qmask communication port
    std::vector<std::string> connectedPeers;

    // 🌐 FUNCTION 1: Registers peer nodes onto your local routing table
    void ConnectToPeer(const std::string& peerIP) {
        connectedPeers.push_back(peerIP);
        std::cout << "[P2P] Successfully linked to node peer: " << peerIP << ":" << defaultPort << "\n";
    }

    // ⚖️ FUNCTION 2: The Competition-Fairness Throttler
    // Calculates a hardware-throttled "Effective Hashrate" to shield older devices
    double CalculateEffectivePower(double rawHardwareThreads) {
        // We use a square root mathematical curve to enforce diminishing returns on high thread counts.
        // 4 threads = 2.0x effective power scaling factor
        // 32 threads = 5.6x effective power scaling factor (instead of 32x!)
        return std::sqrt(rawHardwareThreads) * 100.0;
    }
};

int main() {
    std::cout << "🌐 Initializing Qmask (QMK) P2P Networking & Fairness Subsystem...\n\n";
    
    QmaskNetworkNode localNode;

    // 1. Simulate joining the global decentralized mesh network
    localNode.ConnectToPeer("192.168.1.50");
    localNode.ConnectToPeer("45.77.12.110");
    
    std::cout << "\n----------------------------------------------------------------\n";
    std::cout << "🛡️ TESTING HARDWARE BALANCING MATRIX (CPU THREAD THROTTLING):\n";
    std::cout << "----------------------------------------------------------------\n";

    // Device A: Older CPU device (Running 4 threads)
    double olderCPUThreads = 4.0;
    double olderCPUEffective = localNode.CalculateEffectivePower(olderCPUThreads);
    std::cout << "💻 Older Laptop CPU  (" << olderCPUThreads << " Threads) -> Effective Power: " << olderCPUEffective << " MH/s\n";

    // Device B: Higher-End Workstation CPU (Running 32 threads)
    double highEndCPUThreads = 32.0;
    double highEndCPUEffective = localNode.CalculateEffectivePower(highEndCPUThreads);
    std::cout << "🖥️  High-End Ryzen CPU (" << highEndCPUThreads << " Threads) -> Effective Power: " << highEndCPUEffective << " MH/s\n";

    std::cout << "----------------------------------------------------------------\n";
    // Real-world comparison breakdown
    double rawRatio = highEndCPUThreads / olderCPUThreads;
    double effectiveRatio = highEndCPUEffective / olderCPUEffective;
    
    std::cout << "📊 Without Throttling, High-End is " << rawRatio << "x faster than the older CPU.\n";
    std::cout << "✨ With Qmask Curve, High-End is only " << std::fixed <<  effectiveRatio << "x faster!\n";
    std::cout << "✅ Balance Achieved: Active competition remains, but older hardware can survive.\n";

    return 0;
}
