#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum % 2 != 0)
            return false;

        return knapsack(nums, totalSum / 2);
    }

private:
    bool knapsack(const vector<int>& nums, int targetSum) {
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= n; ++i) {
            int currentNum = nums[i - 1];
            for (int currSum = 0; currSum <= targetSum; ++currSum) {
                if (currSum < currentNum)
                    dp[i][currSum] = dp[i - 1][currSum];
                else
                    dp[i][currSum] = dp[i - 1][currSum] || dp[i - 1][currSum - currentNum];
            }
        }

        return dp[n][targetSum];
    }
};