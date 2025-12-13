#include "../sensors/temperature_sensor.cpp"
#include "../ingest/sensor_ingest.cpp"
#include "../sensors/humidity_sensor.cpp"
#include "../middleware/smoothing_filter.h"
#include "../middleware/trend_detector.h"
#include "../middleware/health_score.h"
#include "../middleware/MovingWindowEnergy.cpp"
#include "../middleware/SignalAverager.cpp"
#include "../middleware/StabilityScoreExtractor.cpp"
#include "risk_classifier.h"
#include "alerts.cpp"
#include <vector>
#include <iostream>

template<typename T>
void logVector(const std::string& name, const std::vector<T>& vec) {
    std::cout << "[DEBUG] " << name << ": ";
    for (const auto& v : vec) std::cout << v << " ";
    std::cout << std::endl;
}

void runSystemCheck() {
    std::vector<double> tempReadings;
    std::vector<double> humReadings;

    for (int i=0;i<10;++i){
        tempReadings.push_back(ingestData(readTemperature()));
        humReadings.push_back(ingestData(readHumidity()));
    }

    SmoothingFilter smooth;
    TrendDetector trend;
    MovingWindowEnergy wme;
    SignalAverager averager;
    StabilityScoreExtractor stability;
    HealthScore health;
    RiskClassifier classifier;

    std::vector<double>  tempSmoothed = smooth.smooth(tempReadings);
    std::vector<double> tempTrend = trend.computeTrend(tempSmoothed);
    std::vector<double>  tempMWE = wme.process(tempTrend);
    std::vector<double> tmpAvg = averager.process(tempMWE);
    std::vector<double>  tmpStable = stability.process(tmpAvg);
    double healthScore = health.compute(tmpAvg, tmpStable);
    double risk = classifier.classify(healthScore, tmpAvg);

    logVector("Temperature readings", tempReadings);
    logVector("Humidity readings", humidReadings);
    showAlert(risk);
}
