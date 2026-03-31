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

        Key() {}
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
            size_t seed = 0;
            std::hash<long long> hash;
            seed ^= hash(k.x) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            seed ^= hash(k.y) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            return seed;
        }
    };

    void WriteWaterPressure(std::vector<WaterPressurePoint>& points);
}