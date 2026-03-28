#include "pch.h"
#include "Task1.h"
#include <unordered_set>
#include <unordered_map>
#include <iomanip>

namespace Task1
{
	void WriteWaterPressure(std::vector<WaterPressurePoint>& points)
    {
        std::ofstream file("Task1Output.txt");
        file << std::fixed << std::setprecision(3);

        std::unordered_map<Key, WaterPressurePoint, KeyHash> hashMap;
        int iConcident = 0;
        for (int i = 0; i < points.size(); i++) {
            Key k = Key(points[i]);
            if (hashMap.find(k) == hashMap.end()) {
                hashMap[k] = points[i];
                points[iConcident++] = points[i];
                file << points[i].x << " " << points[i].y << " " << points[i].water_pressure << std::endl;
            }
            else {
                if (abs(hashMap[k].x - points[i].x) > dDstTol &&
                    abs(hashMap[k].y - points[i].y) > dDstTol)
                {
                    file << points[i].x << " " << points[i].y << " " << points[i].water_pressure << std::endl;
                }
            }
        }
        points.resize(iConcident);
        file.close();
	}
}