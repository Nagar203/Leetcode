class Solution {
public:
    int numberOfWays(int targetSum, int power) {
        constexpr int MOD = 1'000'000'007;
        vector<int> dp(targetSum + 1);
        int powerValue;

        dp[0] = 1;

        for (int baseNumber = 1; (powerValue = pow(baseNumber, power)) <= targetSum; ++baseNumber) {
            for (int currentSum = targetSum; currentSum >= powerValue; --currentSum) {
                dp[currentSum] = (dp[currentSum] + dp[currentSum - powerValue]) % MOD;
            }
        }

        return dp[targetSum];
    }
};
