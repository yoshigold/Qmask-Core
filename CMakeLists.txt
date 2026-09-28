cmake_minimum_required(VERSION 3.10)
project(MONEU CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -static")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpermissive -static-libgcc -static -static-libstdc++")

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/crypto"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/crypto/ed25519-donna"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/consensus"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/primitives"
)

set(DAEMON_SOURCES
    src/main.cpp src/net.cpp src/setup_wizard.cpp src/tactics_core.cpp src/consensus/pow.cpp src/chainparams.cpp
    src/primitives/block.cpp src/primitives/keys.cpp src/wallet_guard.cpp src/primitives/script.cpp src/primitives/transaction.cpp
    src/crypto/arith_uint256.cpp src/crypto/secure_enc.cpp
    src/crypto/sha2.c src/crypto/memzero.c src/crypto/rand.c src/crypto/base58.c src/crypto/hmac.c src/crypto/pbkdf2.c src/crypto/ripemd160.c
    src/crypto/ed25519-donna/ed25519.c src/crypto/ed25519-donna/curve25519-donna-32bit.c src/crypto/ed25519-donna/curve25519-donna-helpers.c src/crypto/ed25519-donna/curve25519-donna-scalarmult-base.c src/crypto/ed25519-donna/ed25519-donna-32bit-tables.c src/crypto/ed25519-donna/ed25519-donna-basepoint-table.c src/crypto/ed25519-donna/ed25519-donna-impl-base.c src/crypto/ed25519-donna/modm-donna-32bit.c
)
set(CLI_SOURCES
    src/wallet_cli_entry.cpp src/net.cpp src/setup_wizard.cpp src/tactics_core.cpp src/consensus/pow.cpp src/chainparams.cpp
    src/primitives/block.cpp src/primitives/keys.cpp src/wallet_guard.cpp src/primitives/script.cpp src/primitives/transaction.cpp
    src/crypto/arith_uint256.cpp src/crypto/secure_enc.cpp
    src/crypto/sha2.c src/crypto/memzero.c src/crypto/rand.c src/crypto/base58.c src/crypto/hmac.c src/crypto/pbkdf2.c src/crypto/ripemd160.c
    src/crypto/ed25519-donna/ed25519.c src/crypto/ed25519-donna/curve25519-donna-32bit.c src/crypto/ed25519-donna/curve25519-donna-helpers.c src/crypto/ed25519-donna/curve25519-donna-scalarmult-base.c src/crypto/ed25519-donna/ed25519-donna-32bit-tables.c src/crypto/ed25519-donna/ed25519-donna-basepoint-table.c src/crypto/ed25519-donna/ed25519-donna-impl-base.c src/crypto/ed25519-donna/modm-donna-32bit.c
)

add_executable(moneud ${DAEMON_SOURCES})
add_executable(moneu-cli ${CLI_SOURCES})

if(WIN32 OR MINGW)
    target_link_libraries(moneud ws2_32 mswsock iphlpapi pthread)
    target_link_libraries(moneu-cli ws2_32 mswsock iphlpapi pthread)
    set_target_properties(moneud PROPERTIES LINK_FLAGS "-static -static-libgcc -static-libstdc++")
    set_target_properties(moneu-cli PROPERTIES LINK_FLAGS "-static -static-libgcc -static-libstdc++")
else()
    target_link_libraries(moneud pthread crypto ssl)
    target_link_libraries(moneu-cli pthread crypto ssl)
endif()
