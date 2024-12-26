#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& numbers, int targetSum) {
        int totalSum = accumulate(numbers.begin(), numbers.end(), 0);

        // Check if the targetSum is achievable
        if (totalSum < abs(targetSum) || (totalSum + targetSum) % 2 == 1) {
            return 0;
        }

        int subsetSum = (totalSum + targetSum) / 2;
        return knapsack(numbers, subsetSum, totalSum);
    }

private:
    int knapsack(const vector<int>& numbers, int subsetSum, int totalSum) {
        // dp[i]: Number of ways to sum to i using numbers so far
        vector<int> dp(totalSum + 1, 0);
        dp[0] = 1;

        for (int num : numbers) {
            for (int j = totalSum; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }

        return dp[subsetSum];
    }
};