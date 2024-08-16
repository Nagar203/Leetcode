#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

class Solution {
public:
    int maxDistance(std::vector<std::vector<int>>& arrays) {
        int maxDistance = 0;  // Initialize the maximum distance to zero
        int currentMin = arrays[0][0];  // Start with the first array's minimum value
        int currentMax = arrays[0].back();  // Start with the first array's maximum value

        // Iterate through each array starting from the second one
        for (int i = 1; i < arrays.size(); ++i) {
            // Get the current array's first and last elements
            int currentArrayFirst = arrays[i][0];
            int currentArrayLast = arrays[i].back();

            // Calculate distances using the first and last elements of the current array
            int distanceFromMax = std::abs(currentArrayFirst - currentMax);  // Distance from the current array's first element to current maximum
            int distanceFromMin = std::abs(currentArrayLast - currentMin);  // Distance from the current array's last element to current minimum

            // Update the maximum distance if the current distances are greater
            maxDistance = std::max(maxDistance, std::max(distanceFromMax, distanceFromMin));

            // Update currentMin and currentMax to include the current array
            currentMin = std::min(currentMin, currentArrayFirst);  // Update current minimum value
            currentMax = std::max(currentMax, currentArrayLast);  // Update current maximum value
        }

        return maxDistance;  // Return the largest distance found
    }
};