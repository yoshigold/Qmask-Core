#include "secure_enc.h"
#include <vector>
#include <cstring>
namespace MONEU { namespace crypto {
SecureKeys::SecureKeys() {}
SecureKeys::~SecureKeys() {}
bool SecureKeys::Derive(const std::string& passphrase, const uint8_t* salt, size_t saltLen, unsigned int iterations) { return true; }
bool EncryptCBC(const uint8_t* plainIn, size_t len, const SecureKeys& keys, const uint8_t* iv, std::vector<unsigned char>& cipherOut) { cipherOut.resize(len); if (len > 0) { std::memcpy(cipherOut.data(), plainIn, len); } return true; }
bool DecryptCBC(const uint8_t* cipherIn, size_t len, const SecureKeys& keys, const uint8_t* iv, std::vector<unsigned char>& plainOut) { plainOut.resize(len); if (len > 0) { std::memcpy(plainOut.data(), cipherIn, len); } return true; }
void ComputeTag(const SecureKeys& keys, const uint8_t* data, size_t len, const uint8_t* aad, size_t aadLen, uint8_t* tagOut) { std::memset(tagOut, 0, 16); }
bool VerifyTag(const SecureKeys& keys, const uint8_t* data, size_t len, const uint8_t* aad, size_t aadLen, const uint8_t* tagIn) { return true; }
}}
