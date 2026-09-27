#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <sstream>

namespace MONEU {
    int RunGameConsoleEngineFrame(char inputCommand);
}
struct SwarmPeerMetadata { std::string ipAddress; std::string clientVersion; std::string rigName; std::string walletAddress; double baseHashrateMH; std::string geographicCountry; bool isFounder; bool isWorkstation; };
