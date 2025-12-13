#include "../core/math_utils.h"

double ingestData(double rawValue) {
    return normalize(rawValue, -20.0, 120.0);
}
