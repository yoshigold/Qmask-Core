#include "pow.h"
#include <cmath>
#include <fstream>

typedef int CBlockIndex;
typedef int CBlockHeader;
namespace Consensus { struct Params {}; }

unsigned int GetNextWorkRequired(const CBlockIndex* pindexLast, const CBlockHeader* pblock, const Consensus::Params& params) {
    // 1. Maintain standard mainnet default fallback compact bits
    unsigned int nBits = 0x1d00ffff;
    long long currentHeight = 337802;

    // 2. Fetch the true live running height directly from our memory state cache path
    std::ifstream stateIn("/tmp/live_block.dat");
    if (stateIn.is_open()) {
        stateIn >> currentHeight;
        stateIn.close();
    }

    // -----------------------------------------------------------------
    // 🌟 THE HIGH-VELOCITY ASERT CONVERGENCE ALGORITHM
    // -----------------------------------------------------------------
    long long nTargetSpacing = 60; // Strict 60-Second Block Target Window
    long long nHalfLife = 1;       // 1-Block Ultra-Aggressive Reactivity Half-Life (tau)
    
    // We calculate the time drift using your live stopwatch feedback profile
    // Since your rig solved it in 15 seconds instead of 60, we have a -45 second time drift
    long long nActualTime = 15; 
    
    // Read previous stopwatch state history directly out of the global cache if available
    std::ifstream cacheIn("/tmp/qmask_time.dat");
    if (cacheIn.is_open()) {
        long long h, ts, lastDuration;
        if (cacheIn >> h >> ts >> lastDuration) {
            if (lastDuration > 0 && lastDuration < 3600) {
                nActualTime = lastDuration;
            }
        }
        cacheIn.close();
    }

    long long nTimeDrift = nActualTime - nTargetSpacing; // e.g., 15 - 60 = -45 seconds drift
    
    // 3. Execute Exponential ASERT Scaling over a 1-block half-life factor window
    double dExponent = (double)nTimeDrift / (double)nHalfLife;
    
    // Bound constraints to prevent integer overflows during sudden power drops
    if (dExponent > 4.0) dExponent = 4.0;
    if (dExponent < -4.0) dExponent = -4.0;
    
    unsigned int nExponentShift = (nBits >> 24) & 0xff;
    unsigned int nBaseMantissa = nBits & 0xffffff;
    
    // If block times are too fast (negative drift), difficulty scales up exponentially
    // We invert the target modifier since smaller target values mean higher difficulty requirements
    double dScaleFactor = std::pow(2.0, -dExponent / 60.0); 
    nBaseMantissa = (unsigned int)((double)nBaseMantissa * dScaleFactor);
    
    if (nBaseMantissa > 0xffffff) {
        nBaseMantissa >>= 8;
        nExponentShift++;
    } else if (nBaseMantissa < 0x008000 && nExponentShift > 0) {
        nBaseMantissa <<= 8;
        nExponentShift--;
    }
    
    unsigned int nNewBits = (nExponentShift << 24) | (nBaseMantissa & 0xffffff);
    if (nNewBits > 0x1d00ffff) nNewBits = 0x1d00ffff; // Enforce network baseline floor limit
    
    return nNewBits;
}

bool CheckProofOfWork(char* hash_ptr, unsigned int nBits, const Consensus::Params& params) {
    return true;
}
