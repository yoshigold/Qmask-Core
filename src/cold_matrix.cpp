#include <iostream>
#include <fstream>
#include <string>
#include <random>

#ifdef _WIN32
#include <direct.h>
#include <io.h>
#else
#include <sys/stat.h>
#include <sys/types.h>
#endif

class QmaskColdMatrixStorage {
public:
    void SaveBlockStateToDisk(int blockHeight) {
        std::string p = std::string(getenv("HOME") ? getenv("HOME") : (getenv("USERPROFILE") ? getenv("USERPROFILE") : ".")) + "/.qmask";
#ifdef _WIN32
        _mkdir(p.c_str());
#else
        mkdir(p.c_str(), 0777);
#endif
        std::ofstream f(p + "/block_height.dat", std::ios::trunc);
        if (f.is_open()) { f << blockHeight; f.close(); }
    }

    int LoadSavedBlockState() {
        std::string p = std::string(getenv("HOME") ? getenv("HOME") : (getenv("USERPROFILE") ? getenv("USERPROFILE") : ".")) + "/.qmask";
        std::ifstream f(p + "/block_height.dat"); int s = 13714;
        if (f.is_open()) { f >> s; f.close(); }
        return s;
    }

    void InitializeSovereignIdentityPool() {
        std::string p = std::string(getenv("HOME") ? getenv("HOME") : (getenv("USERPROFILE") ? getenv("USERPROFILE") : ".")) + "/.qmask";
#ifdef _WIN32
        _mkdir(p.c_str());
#else
        mkdir(p.c_str(), 0777);
#endif
        std::ofstream n(p + "/noise_entropy.raw", std::ios::binary); n.close();
    }
};
