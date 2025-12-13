#pragma once
#include <iostream>

bool isCritical(double riskScore) {
    return riskScore > 0.8;
}

void showAlert(double riskScore) {
    if (isCritical(riskScore))
        std::cout << "⚠️ ALERT! Risk threshold exceeded: " << riskScore << "\n";
    else
        std::cout << "✅ Risk normal: " << riskScore << "\n";
}
