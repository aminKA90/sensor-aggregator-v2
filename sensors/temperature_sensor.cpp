#include "sensor_registry.h"
#include <cstdlib>
#include <ctime>

double readTemperature() {
    static bool seeded = false;
    if (!seeded) { std::srand((unsigned int)std::time(nullptr)); seeded = true; }
    return 20.0 + (std::rand() % 1500) / 100.0; // 20–35°C
}
