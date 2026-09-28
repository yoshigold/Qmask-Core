#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

class QmaskTelemetryPricingEngine {
public:
    // ⚡ 1. NATIVE HARDWARE HEALTH TASK MANAGER: Records hardware metrics
    void DisplayAdvancedTaskManager(const std::string& cpuModel, double gigahertz, double utilization, double wattage, double temperatureCelsius) {
        std::cout << "🖥️  =========================================================\n";
        std::cout << "🖥️  ALPHA-0 EMBEDDED TASK MANAGER & COMPUTER HEALTH MONITOR   \n";
        std::cout << "🖥️  =========================================================\n";
        std::cout << "📋 Processor Model   : " << cpuModel << "\n";
        std::cout << "🏎️  Clock Speed Speed : " << gigahertz << " GHz | Utilization: " << utilization << "%\n";
        std::cout << "⚡ Energy Draw Consumption: " << wattage << " Watts\n";
        std::cout << "🌡️  Core Temperature  : " << temperatureCelsius << " C\n";
        std::cout << "----------------------------------------------------------------\n";
    }

    // 🧮 2. ALGORITHMIC THERMODYNAMIC PRICING MATRIX (Minting the QJM Price Tag)
    double CalculateNativeJoulePriceTag(double currentDifficulty, double hardwareWattage, double activeHashrateMhs) {
        // Calculate the raw Wattage-per-Hash efficiency footprint
        double wattagePerHash = hardwareWattage / (activeHashrateMhs + 0.001);
        std::cout << "📊 Energy Metric: Wattage-per-Hash Efficiency Layer = " << std::fixed << std::setprecision(6) << wattagePerHash << " W/Hash\n";

        // Compute our custom native asset price formula (Pure thermodynamic density scaling)
        double internalJoulePrice = (currentDifficulty * hardwareWattage) / 100000.0;
        
        std::cout << "⚡ [QJM Price Engine] Algorithmic Energy Price Tag Generated:\n";
        std::cout << "   ✨ 1 QJM (Qmask Joule Metric) = " << std::fixed << std::setprecision(4) << internalJoulePrice << " Local Value Units\n";
        std::cout << "----------------------------------------------------------------\n\n";
        return internalJoulePrice;
    }
};