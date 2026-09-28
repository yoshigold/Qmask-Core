#!/bin/bash
echo "================================================================="
echo "   🎭 QMTM SEPARATE GAME NETWORK ARCHIVE AUTOMATION SUITE 🎭     "
echo "================================================================="
echo "⚙️  Step 1: Synchronizing file memory caches and folder trees..."
mkdir -p build release_game

# Hard-reset local memory metrics to secure your 132.50000000 QMTM wealth tracks
echo "4 2 12 4 0 0 8 3 0 0 100 100 132.50000000 0" > game_state.dat

echo "⚙️  Step 2: Executing direct multi-file g++ compilation pass..."
g++ -O3 -std=c++17 src/wallet_cli_entry.cpp src/tactics_core.cpp -o build/moneu-cli
chmod +x build/moneu-cli

echo "⚙️  Step 3: Staging binary payload tracks for distribution..."
cp build/moneu-cli release_game/
cp game_state.dat release_game/

# Create a rapid native gamepad launch shortcut file for the zip container
cat << 'LAUNCH' > release_game/launch_gamepad.sh
#!/bin/bash
clear && printf "\033[3J"
./moneu-cli --game-panel ' '
while true; do
    read -rsn1 key
    if [[ "$key" == $'\x1b' ]]; then read -rsn2 -t 0.05 target; continue; fi
    if [[ "$key" =~ ^[wWaAsSdD123pP]$ ]]; then ./moneu-cli --game-panel "$key"; fi
done
LAUNCH
chmod +x release_game/launch_gamepad.sh

echo "⚙️  Step 4: Compressing production QMTM gaming zip container..."
rm -f qmtm_game_adventure_release.zip
zip -r qmtm_game_adventure_release.zip release_game/

echo "🧹 Step 5: Performing workspace optimization sweeps..."
rm -rf release_game/

echo "================================================================="
echo " 🎁 SUCCESS: qmtm_game_adventure_release.zip BUILT LIVE!         "
echo "================================================================="
