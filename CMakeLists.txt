cmake_minimum_required(VERSION 3.10)
project(QmaskCore)

set(CMAKE_CXX_STANDARD 17)

# 💻 MULTI-PLATFORM LIBRARY STRUCTURING FILTER
if(WIN32)
    # Windows Compilation Paths
    set(OPENSSL_USE_STATIC_LIBS TRUE)
    find_package(OpenSSL REQUIRED)
    set(UPNP_LIBS miniupnpc)
    add_definitions(-D_WIN32_WINNT=0x0601) # Target Windows 7/10+ baseline
else()
    # Native Linux VM Compilation Paths
    set(UPNP_LIBS miniupnpc)
    set(CRYPTO_LIBS ssl crypto)
endif()

# 🧱 TARGET 1: The Continuous Mainnet Node Daemon Engine (moneud)
add_executable(moneud 
    src/main.cpp
    src/net.cpp
    src/tactics_core.cpp
    src/setup_wizard.cpp
    src/wallet_guard.cpp
    src/cold_matrix.cpp
)
target_link_libraries(moneud ${CRYPTO_LIBS} ${OPENSSL_LIBRARIES} ${UPNP_LIBS})

# 🎛️ TARGET 2: The Command-Line Wallet Interface Controller (moneu-cli)
add_executable(moneu-cli 
    src/wallet_cli_entry.cpp
    src/net.cpp
    src/wallet_guard.cpp
    src/setup_wizard.cpp
)
target_link_libraries(moneu-cli ${CRYPTO_LIBS} ${OPENSSL_LIBRARIES} ${UPNP_LIBS})
