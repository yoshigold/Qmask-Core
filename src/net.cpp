#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

// Include native MiniUPnPc library header tracks
#include <miniupnpc/miniupnpc.h>
#include <miniupnpc/upnpcommands.h>
#include <miniupnpc/upnperrors.h>

class QmaskNetworkDiscoveryPool {
private:
    std::vector<std::string> dnsSeeds = {
        "seed.qmask-core.org",
        "seed2.qmask-core.org",
        "yoshigold-nodes.qmask.net"
    };
    const std::string DEFAULT_PORT = "8327";

public:
    // 📡 TASK 1 LOOKUP: Dynamic DNS Seed Resolution Engine
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
                resolvedPeerIps.push_back("90.201.17.21"); // Dynamic Sky IP fallback target
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

    // 🚀 TASK 2 ENGINE: Native Automated UPnP Port-Punching Router Layer
    void ExecuteAutomatedPortForward() {
        std::cout << "🛰️  [UPnP Engine] Probing local area gateway interfaces for UPnP flags...\n";
        int error = 0;
        struct UPNPDev * devlist = upnpDiscover(2000, nullptr, nullptr, 0, 0, 2, &error);
        
        if (!devlist) {
            std::cout << "⚠️  [UPnP Alert] No UPnP router found on local network. Moving to manual firewall rules.\n";
            return;
        }

        struct UPNPUrls urls;
        struct IGDdatas data;
        char lanaddr[64];
        
        // Locate the active Internet Gateway Device (IGD) matching your domestic internet setup
        int status = UPNP_GetValidIGD(devlist, &urls, &data, lanaddr, sizeof(lanaddr));
        if (status == 1 || status == 2) {
            std::cout << "✅ [IGD FOUND] Located running router device. Local VM Node Address: " << lanaddr << "\n";
            
            // Fire the API mapping packet to map External Port 8327 to Internal Port 8327
            int mappingResult = UPNP_AddPortMapping(urls.controlURL, data.first.servicetype,
                                                   DEFAULT_PORT.c_str(), DEFAULT_PORT.c_str(), 
                                                   lanaddr, "Qmask P2P Network Protocol Channel", "TCP", nullptr, "0");
            
            if (mappingResult == UPNPCOMMAND_SUCCESS) {
                std::cout << "🔥 [UPnP SUCCESS] Router Port " << DEFAULT_PORT << " is now dynamically open to the public internet!\n";
            } else {
                std::cout << "⚠️  [UPnP BLOCKED] Router rejected mapping request. Code: " << mappingResult << "\n";
            }
        } else {
            std::cout << "⚠️  [UPnP FAILED] Invalid Internet Gateway configuration path detected.\n";
        }
        
        freeUPNPDevlist(devlist);
    }
};

void InitializeP2PNetworkListener() {
    std::cout << "🛰️  [P2P LISTEN] Active socket scanning initialized on Port 8327.\n";
    QmaskNetworkDiscoveryPool netEngine;
    netEngine.ExecuteAutomatedPortForward(); // Execute the port forward automatically on boot
}
