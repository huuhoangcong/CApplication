#pragma once
#include "pch.h"

namespace Task1 {
    const double dDstTol = 1e-03;
    const double dHashTol = 1e-06;

    struct WaterPressurePoint {
        double x;
        double y;
        double water_pressure;
    };

    struct Key
    {
        long long x, y;

        Key(const WaterPressurePoint& point)
        {
            x = (long long)(point.x / dHashTol);
            y = (long long)(point.y / dHashTol);
        }

        bool operator==(const Key& other) const
        {
            return x == other.x && y == other.y;
        }
    };

    struct KeyHash
    {
        size_t operator()(const Key& k) const
        {
            return std::hash<long long>()(k.x) ^ (std::hash<long long>()(k.y) << 1);
        }
    };

    void WriteWaterPressure(std::vector<WaterPressurePoint>& points);
}