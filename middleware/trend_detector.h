#pragma once
#include <vector>

class TrendDetector {
public:
    std::vector<double> computeTrend(
        const std::vector<double>& values,
        size_t window = 3
    ) const {
        std::vector<double> trends;
        if (values.empty() || window < 2) return trends;

        trends.reserve(values.size());

        for (size_t i = 0; i < values.size(); ++i) {
            if (i < window - 1) {
                trends.push_back(0.0);  // insufficient history
            } else {
                trends.push_back(values[i] - values[i - (window - 1)]);
            }
        }
        return trends;
    }
};
