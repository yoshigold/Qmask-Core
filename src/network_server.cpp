#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <thread>
#include <chrono>

void ExecuteUPnPPortMapping() {
    std::cout << "📡 [UPNP PROTOCOL] Initiating BitTorrent-style SSDP discovery matrix...\n";
    int upnpResult = std::system("upnpc -r 18332 TCP 2>/dev/null");
    if (upnpResult == 0) {
        std::cout << "\033[1;32m✅ [UPNP SUCCESS] Router firewall breached! External Port :18332 opened automatically!\033[0m\n";
    } else {
        std::cout << "⚠️  [UPNP NOTICE] Local router UPnP disabled or pending. Falling back to local LAN socket lines.\n";
    }
}

void HandleNetworkPeerConnection(int clientSocket) {
    char communicationBuffer[1024] = {0};
    ssize_t networkBytesRead = read(clientSocket, communicationBuffer, 1024);
    if (networkBytesRead > 0) {
        std::string mockBlockPayload = "QMASK_BLOCK_SYNC_OK HEIGHT:#340246 DIFF:400000000000 STATUS:VALIDATED\n";
        send(clientSocket, mockBlockPayload.c_str(), mockBlockPayload.length(), 0);
    }
    close(clientSocket);
}

void StartNetworkMeshServer() {
    std::thread(ExecuteUPnPPortMapping).detach();
    int serverFd = socket(AF_INET, SOCK_STREAM, 0);
    int optimalSocketOption = 1;
    setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &optimalSocketOption, sizeof(optimalSocketOption));
    struct sockaddr_in addressSet;
    addressSet.sin_family = AF_INET;
    addressSet.sin_addr.s_addr = INADDR_ANY;
    addressSet.sin_port = htons(18332);
    bind(serverFd, (struct sockaddr*)&addressSet, sizeof(addressSet));
    listen(serverFd, 10);
    while (true) {
        int peerSocket = accept(serverFd, nullptr, nullptr);
        if (peerSocket >= 0) {
            std::thread(HandleNetworkPeerConnection, peerSocket).detach();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
