class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        const int furthestFruitPos = max(startPos, fruits.back()[0]);
        int maxFruitsCollected = 0;

        vector<int> fruitAmounts(furthestFruitPos + 1);
        vector<int> prefixSum(furthestFruitPos + 2);

        for (const vector<int>& fruit : fruits)
            fruitAmounts[fruit[0]] = fruit[1];

        partial_sum(fruitAmounts.begin(), fruitAmounts.end(),
                    prefixSum.begin() + 1);

        auto collectFruits = [&](int leftSteps, int rightSteps) {
            int leftBound = max(0, startPos - leftSteps);
            int rightBound = min(furthestFruitPos, startPos + rightSteps);
            return prefixSum[rightBound + 1] - prefixSum[leftBound];
        };

        // Move right first
        int maxRightSteps = min(furthestFruitPos - startPos, k);
        for (int rightSteps = 0; rightSteps <= maxRightSteps; ++rightSteps) {
            int leftSteps = max(0, k - 2 * rightSteps);
            maxFruitsCollected =
                max(maxFruitsCollected, collectFruits(leftSteps, rightSteps));
        }

        // Move left first
        int maxLeftSteps = min(startPos, k);
        for (int leftSteps = 0; leftSteps <= maxLeftSteps; ++leftSteps) {
            int rightSteps = max(0, k - 2 * leftSteps);
            maxFruitsCollected =
                max(maxFruitsCollected, collectFruits(leftSteps, rightSteps));
        }

        return maxFruitsCollected;
    }
};
