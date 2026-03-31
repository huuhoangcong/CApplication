#pragma once
#include "pch.h"

namespace Task1 {
    const double dDstTol = 1e-03;

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
            x = (long long)(point.x / dDstTol);
            y = (long long)(point.y / dDstTol);
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