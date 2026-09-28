#!/bin/bash
git remote remove origin 2>/dev/null || true
git remote add origin https://github.com/yoshigold/Qmask-Core.git
git add .
git commit -m "Mainnet Launch Core v1.4.5: Hardlocked Dynamic Block Metrics and Thread-Safe Boss AI Systems." -a 2>/dev/null || true
git push -f origin rpg-campaign-build
