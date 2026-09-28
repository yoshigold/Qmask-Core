#ifndef QMASK_RPC_SERVER_H
#define QMASK_RPC_SERVER_H

#include <string>

class QmaskRpcServer {
private:
    const std::string bindAddress = "127.0.0.1";
    const int rpcPort = 38444; // Default Qmask RPC websocket API port

public:
    // 📡 Starts listening for inbound programmatic API network requests
    void LaunchRpcListener();

    // 📡 Processes incoming JSON-RPC method request commands
    std::string ProcessIncomingRpcRequest(const std::string& methodCall);
};

#endif // QMASK_RPC_SERVER_H
