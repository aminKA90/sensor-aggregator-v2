#pragma once
#include <vector>
#include <numeric>
#include <cmath>

class HealthScore {
public:
    double compute(
        const std::vector<double>& smoothed,
        const std::vector<double>& trend
    ) const {
        if (smoothed.empty() || trend.empty()) return 0.0;

        // Average signal magnitude
        double avgValue =
            std::accumulate(smoothed.begin(), smoothed.end(), 0.0) / smoothed.size();

        // Average trend magnitude
        double avgTrend =
            std::accumulate(trend.begin(), trend.end(), 0.0) / trend.size();

        // Linear combination (no thresholds, no normalization)
        return 0.8 * avgValue + 0.2 * avgTrend;
    }
};
