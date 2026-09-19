#include "block_packer.h"
#include <iostream>
#include <sstream>
#include <iomanip>

// 📦 LOGIC: Packs header variables and transaction hashes into a clean, serialized ledger data footprint
std::string QmaskBlockPacker::PackBlockData(int blockHeight, const std::string& prevBlockHash, const std::vector<std::string>& txList) {
    unsigned int packageHash = 7331; // Distinct polynomial seed matrix for serialization tracking

    // Inject block height and link indices into the rolling hash calculation
    packageHash = ((packageHash << 5) + packageHash) + blockHeight;
    for (char c : prevBlockHash) packageHash = ((packageHash << 5) + packageHash) + c;

    // Pack each individual transaction payload string sequentially into the matrix loop
    for (const std::string& tx : txList) {
        for (char c : tx) packageHash = ((packageHash << 5) + packageHash) + c;
    }

    // Convert the complete packed object into an immutable 32-character hexadecimal block hash root
    std::stringstream ss;
    ss << std::hex << std::setw(8) << std::setfill('0') << packageHash;
    std::string blockRoot = "0000_block_root_" + ss.str();

    while (blockRoot.length() < 32) {
        blockRoot += "a";
    }

    return blockRoot;
}
