#pragma once
#include <vector>

class StabilityScoreExtractor {
public:
    std::vector<double> process(const std::vector<double>& values) const {
        std::vector<double> scores;
        if (values.empty()) return scores;

        scores.reserve(values.size());
        double running = values[0];

        for (double v : values) {
            running = 0.8 * running + 0.2 * v;
            scores.push_back(running);
        }
        return scores;
    }
};
