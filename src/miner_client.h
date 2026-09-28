#ifndef QMASK_MINER_CLIENT_H
#define QMASK_MINER_CLIENT_H

#include <string>

class QmaskMinerClient {
private:
    const std::string targetNodeUrl = "ws://127.0.0.1:38444";

public:
    // ⛏️ Pings the local node via RPC to pull down current work jobs
    void RequestBlockTemplate();

    // ⛏️ Simulates GPU hashing pipelines crunching a block range
    void SimulateGpuMining(double difficulty);
};

#endif // QMASK_MINER_CLIENT_H
