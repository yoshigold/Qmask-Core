#include <iostream>
#include <string>
#include <vector>
#include <cstring>

// 💻 MULTI-PLATFORM NETWORKING MATRIX
#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    // Comment miniupnpc out temporarily on raw cross-compiler to ensure rapid .exe assembly
#else
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netdb.h>
    #include <arpa/inet.h>
    #include <miniupnpc/miniupnpc.h>
    #include <miniupnpc/upnpcommands.h>
    #include <miniupnpc/upnperrors.h>
#endif

class QmaskNetworkDiscoveryPool {
private:
    std::vector<std::string> dnsSeeds = {
        "seed.qmask-core.org",
        "seed2.qmask-core.org",
        "yoshigold-nodes.qmask.net"
    };
    const std::string DEFAULT_PORT = "8327";

public:
    std::vector<std::string> ResolveMasterDnsSeeds() {
        std::vector<std::string> resolvedPeerIps;
        std::cout << "📡 [DNS Seed Engine] Initializing anchor hostname routing passes...\n";
        struct addrinfo hints, *res, *p;
        std::memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;

        for (const std::string& seed : dnsSeeds) {
            int status = getaddrinfo(seed.c_str(), DEFAULT_PORT.c_str(), &hints, &res);
            if (status != 0) {
                resolvedPeerIps.push_back("90.201.17.21"); 
                continue;
            }
            for (p = res; p != nullptr; p = p->ai_next) {
                struct sockaddr_in* ipv4 = (struct sockaddr_in*)p->ai_addr;
                char ipBuffer[INET_ADDRSTRLEN];
                inet_ntop(AF_INET, &(ipv4->sin_addr), ipBuffer, INET_ADDRSTRLEN);
                resolvedPeerIps.push_back(std::string(ipBuffer));
            }
            freeaddrinfo(res);
        }
        return resolvedPeerIps;
    }

    void ExecuteAutomatedPortForward() {
        #ifdef _WIN32
            std::cout << "🛰️  [UPnP Engine] UPnP monitoring bypassed for native Windows executable compile layer.\n";
        #else
            std::cout << "🛰️  [UPnP Engine] Probing local area gateway interfaces for UPnP flags...\n";
            int error = 0;
            struct UPNPDev * devlist = upnpDiscover(2000, nullptr, nullptr, 0, 0, 2, &error);
            if (!devlist) return;
            struct UPNPUrls urls; struct IGDdatas data; char lanaddr;
            int status = UPNP_GetValidIGD(devlist, &urls, &data, lanaddr, sizeof(lanaddr));
            if (status == 1 || status == 2) {
                UPNP_AddPortMapping(urls.controlURL, data.first.servicetype, DEFAULT_PORT.c_str(), DEFAULT_PORT.c_str(), lanaddr, "Qmask P2P Channel", "TCP", nullptr, "0");
            }
            freeUPNPDevlist(devlist);
        #endif
    }
};

void InitializeP2PNetworkListener() {
    std::cout << "🛰️  [P2P LISTEN] Active socket scanning initialized on Port 8327.\n";
    #ifdef _WIN32
        // Windows dynamic socket boot init loop
        WSADATA wsaData;
        WSAStartup(MAKEWORD(2,2), &wsaData);
    #endif
    QmaskNetworkDiscoveryPool netEngine;
    netEngine.ExecuteAutomatedPortForward();
}
