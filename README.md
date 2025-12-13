# Sensor Aggregator

This repo aggregates sensor readings.

## Structure

- core/          → normalization & helpers
- sensors/       → temperature & humidity sensors
- middleware/    → smoothing, trend detection, health scoring
- service/       → risk classifier & alerts
- main.cpp       → entry point

## How to test

1. Build & run:
```bash
g++ -std=c++17 main.cpp -o sensor_app
./sensor_app
