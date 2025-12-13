#pragma once

// Normalization utility — this is what we will "break"
inline double normalize(double value, double minVal, double maxVal) {
    return (value - minVal) / (maxVal - minVal);
}

// Another helper function (looks unrelated)
inline double scaleValue(double value, double factor) {
    return value * factor;
}
