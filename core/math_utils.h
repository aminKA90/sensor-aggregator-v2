#pragma once

// Normalization utility — this is what we will "break"
inline double normalize(double value, double minVal, double maxVal) {
    if (maxVal - minVal == 0) return 0.0;
    return (value - minVal) / (maxVal - minVal)*100.0;
}

// Another helper function (looks unrelated)
inline double scaleValue(double value, double factor) {
    return value * factor;
}
