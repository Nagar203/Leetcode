#include <numeric>
#include <vector>

class Solution {
public:
    int minSteps(int totalA) {
        if (totalA <= 1)
            return 0;

        // steps[i]: the minimum steps to get i 'A's
        std::vector<int> minStepsForA(totalA + 1);

        // Copy 'A', then paste 'A' i - 1 times.
        std::iota(minStepsForA.begin(), minStepsForA.end(), 0);

        for (int currentA = 2; currentA <= totalA; ++currentA) {
            for (int divisor = currentA / 2; divisor > 2; --divisor) {
                if (currentA % divisor == 0) {
                    minStepsForA[currentA] = minStepsForA[divisor] + currentA / divisor; // Paste minStepsForA[divisor] currentA / divisor times.
                    break;
                }
            }
        }

        return minStepsForA[totalA];
    }
};