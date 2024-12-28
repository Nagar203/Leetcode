#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> calculateSubArraySums(vector<int>& nums, int subArraySize) {
        int currentSum = 0;
        vector<int> subArraySums;

        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];

            // Start forming subarrays after the first subArraySize elements
            if (i >= subArraySize - 1) {
                subArraySums.push_back(currentSum);
                currentSum -= nums[i - subArraySize + 1];
            }
        }

        return subArraySums;
    }

    int calculateMaxSum(int remainingCount, int startIndex, int subArraySize, vector<int>& subArraySums, vector<vector<int>>& dp) {
        if (startIndex >= subArraySums.size() || remainingCount == 0) {
            return 0;
        }

        if (dp[remainingCount][startIndex] != -1) {
            return dp[remainingCount][startIndex];
        }

        // Include current subarray
        int includeCurrent = subArraySums[startIndex] + calculateMaxSum(remainingCount - 1, startIndex + subArraySize, subArraySize, subArraySums, dp);

        // Skip current subarray
        int excludeCurrent = calculateMaxSum(remainingCount, startIndex + 1, subArraySize, subArraySums, dp);

        dp[remainingCount][startIndex] = max(includeCurrent, excludeCurrent);
        return dp[remainingCount][startIndex];
    }

    void solve(int subArraySize, int remainingCount, int currentIndex, vector<int>& resultIndices, vector<int>& subArraySums, vector<vector<int>>& dp) {
        while (remainingCount > 0 && currentIndex < subArraySums.size()) {
            int includeCurrent = subArraySums[currentIndex] + calculateMaxSum(remainingCount - 1, currentIndex + subArraySize, subArraySize, subArraySums, dp);
            int excludeCurrent = calculateMaxSum(remainingCount, currentIndex + 1, subArraySize, subArraySums, dp);

            if (includeCurrent >= excludeCurrent) {
                resultIndices.push_back(currentIndex);
                remainingCount--;
                currentIndex += subArraySize;
            } else {
                currentIndex++;
            }
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int subArraySize) {
        vector<int> resultIndices;
        vector<int> subArraySums = calculateSubArraySums(nums, subArraySize);
        int n = subArraySums.size();
        vector<vector<int>> dp(4, vector<int>(n, -1)); // 4 rows for up to 3 subarrays + base case

        solve(subArraySize, 3, 0, resultIndices, subArraySums, dp);
        return resultIndices;
    }
};