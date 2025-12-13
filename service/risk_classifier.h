#pragma once
#include <vector>
#include <cmath>

class RiskClassifier {
public:
    double classify(
        double healthScore,
        const std::vector<double>& smoothed
    ) const {
        if (smoothed.size() < 2) return healthScore;

        // Compute average absolute change (volatility)
        double totalDelta = 0.0;
        for (size_t i = 1; i < smoothed.size(); ++i) {
            totalDelta += std::abs(smoothed[i] - smoothed[i - 1]);
        }

        double avgVolatility = totalDelta / (smoothed.size() - 1);

        // Combine health and volatility (no thresholds, no normalization)
        return healthScore + 0.5 * avgVolatility;
    }
};
