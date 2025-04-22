#include <vector>
using namespace std;

class Solution {
public:
    int idealArrays(int arrayLength, int maxValue) {
        const int maxSequenceLength = min(14, arrayLength);
        const vector<vector<int>> factorList = getFactors(maxValue);
        vector<vector<long>> dp(maxSequenceLength + 1, vector<long>(maxValue + 1));
        vector<vector<long>> combinationMemo(arrayLength, vector<long>(maxSequenceLength, -1));
        long totalCount = 0;

        for (int value = 1; value <= maxValue; ++value){
            dp[1][value] = 1;
        }
        for (int length = 2; length <= maxSequenceLength; ++length){
            for (int value = 1; value <= maxValue; ++value){
                for (const int factor : factorList[value]) {
                    dp[length][value] += dp[length - 1][factor];
                    dp[length][value] %= kMod;
                }
            }
        }

        for (int length = 1; length <= maxSequenceLength; ++length)
            for (int value = 1; value <= maxValue; ++value) {
                dp[length][0] += dp[length][value];
                dp[length][0] %= kMod;
            }

        for (int length = 1; length <= maxSequenceLength; ++length) {
            totalCount += dp[length][0] * computeCombination(arrayLength - 1, length - 1, combinationMemo);
            totalCount %= kMod;
        }

        return totalCount;
    }

private:
    static constexpr int kMod = 1'000'000'007;

    vector<vector<int>> getFactors(int maxValue) {
        vector<vector<int>> factorList(maxValue + 1);
        for (int divisor = 1; divisor <= maxValue; ++divisor){
            for (int multiple = divisor * 2; multiple <= maxValue; multiple += divisor){
                factorList[multiple].push_back(divisor);
            }
        }
        return factorList;
    }

    long computeCombination(int n, int k, vector<vector<long>>& memo) {
        if (k == 0 || n == k){
            return 1;
        }
        if (memo[n][k] != -1){
            return memo[n][k];
        }
        return memo[n][k] = (computeCombination(n - 1, k, memo) + computeCombination(n - 1, k - 1, memo)) % kMod;
    }
};