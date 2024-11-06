#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int previousSetBits = 0;
        int previousMax = INT_MIN;  // The maximum of the previous segment
        int currentMax = INT_MIN;   // The maximum of the current segment
        int currentMin = INT_MAX;   // The minimum of the current segment

        for (const int number : nums) {
            int setBitsCount = __builtin_popcount(number);
            if (setBitsCount != previousSetBits) {  // Start a new segment
                if (previousMax > currentMin)
                    return false;
                previousSetBits = setBitsCount;
                previousMax = currentMax;
                currentMax = number;
                currentMin = number;
            } else {  // Continue with the current segment
                currentMax = max(currentMax, number);
                currentMin = min(currentMin, number);
            }
        }

        return previousMax <= currentMin;
    }
};