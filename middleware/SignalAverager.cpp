#pragma once
#include <vector>
#include <numeric>

class SignalAverager {
public:
    std::vector<double> process(const std::vector<double>& values) const {
        std::vector<double> averaged;
        if (values.size() < 2) return averaged;

        for (size_t i = 1; i < values.size(); ++i) {
            averaged.push_back((values[i] + values[i-1]) / 2.0);
        }
        return averaged;
    }
};
