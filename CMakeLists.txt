cmake_minimum_required(VERSION 3.10)
project(QmaskCore)

set(CMAKE_CXX_STANDARD 17)

# 🧱 TARGET 1: The Continuous Mainnet Node Daemon Engine (moneud)
add_executable(moneud 
    src/main.cpp
    src/net.cpp
    src/tactics_core.cpp
    src/setup_wizard.cpp
    src/wallet_guard.cpp
    src/cold_matrix.cpp
)

# 🎛️ TARGET 2: The Command-Line Wallet Interface Controller (moneu-cli)
add_executable(moneu-cli 
    src/wallet_cli_entry.cpp
    src/net.cpp
    src/wallet_guard.cpp
    src/setup_wizard.cpp
)
