#pragma once
#include <vector>
#include <algorithm>

class MovingWindowEnergy {
public:
    std::vector<double> process(const std::vector<double>& values) const {
        std::vector<double> energy;
        if (values.size() < 3) return energy;

        for (size_t i = 2; i < values.size(); ++i) {
            double e = values[i] + values[i-1] + values[i-2];
            energy.push_back(e / 3.0); // still scale preserving
        }
        return energy;
    }
};
