#include "sensor_registry.h"
#include <cstdlib>
#include <ctime>

double readHumidity() {
    static bool seeded = false;
    if (!seeded) { std::srand((unsigned int)std::time(nullptr)); seeded = true; }
    return 30.0 + (std::rand() % 700) / 10.0; // 30–100%
}
