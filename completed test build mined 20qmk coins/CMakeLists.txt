cmake_minimum_required(VERSION 3.10)
project(QmaskCore)

set(CMAKE_CXX_STANDARD 17)

# Link ONLY the critical base-layer files for your running node daemon
add_executable(moneud 
    src/main.cpp
    src/net.cpp
    src/tactics_core.cpp
    src/setup_wizard.cpp
    src/wallet_guard.cpp
    src/cold_matrix.cpp
)
