#pragma once
#include <vector>

class SmoothingFilter {
public:
    std::vector<double> smooth(
        const std::vector<double>& values,
        size_t window = 3
    ) const {
        std::vector<double> result;
        if (values.empty() || window == 0) return result;

        result.reserve(values.size());

        for (size_t i = 0; i < values.size(); ++i) {
            double sum = 0.0;
            size_t count = 0;

            size_t start = (i >= window - 1) ? i - (window - 1) : 0;
            for (size_t j = start; j <= i; ++j) {
                sum += values[j];
                ++count;
            }

            result.push_back(sum / count);
        }
        return result;
    }
};