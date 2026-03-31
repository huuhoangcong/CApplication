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

            // find around 3x3 grid for double precision
            bool bFound = false;
            for (int dx = -1; dx <= 1 && !bFound; ++dx) {
                for (int dy = -1; dy <= 1 && !bFound; ++dy) {
                    Key gridKey;
                    gridKey.x = k.x + dx;
                    gridKey.y = k.y + dy;
                    if (hashMap.count(gridKey) > 0) {
                        if (abs(hashMap[gridKey].x - points[i].x) < dDstTol &&
                            abs(hashMap[gridKey].y - points[i].y) < dDstTol)
                        {
                            bFound = true;
                        }
                    }
                }
            }

            if (!bFound) {
                hashMap[k] = points[i];
                points[iConcident++] = points[i];
                file << points[i].x << " " << points[i].y << " " << points[i].water_pressure << std::endl;
            }
        }
        points.resize(iConcident);
        file.close();
	}
}