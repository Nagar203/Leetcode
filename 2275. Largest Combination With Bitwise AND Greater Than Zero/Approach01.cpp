#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        constexpr int maxBitPosition = 24;
        int maxCount = 0;

        for (int bitPosition = 0; bitPosition < maxBitPosition; ++bitPosition) {
            int currentBitCount = 0;
            for (const int candidate : candidates) {
                if (candidate >> bitPosition & 1)
                    ++currentBitCount;
            }
            maxCount = max(maxCount, currentBitCount);
        }

        return maxCount;
    }
};