#ifndef QMASK_BLOCK_PACKER_H
#define QMASK_BLOCK_PACKER_H

#include <string>
#include <vector>

class QmaskBlockPacker {
public:
    // 📦 Aggregates block parameters and transaction arrays into a serialized data string footprint
    std::string PackBlockData(int blockHeight, const std::string& prevBlockHash, const std::vector<std::string>& txList);
};

#endif // QMASK_BLOCK_PACKER_H
