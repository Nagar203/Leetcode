#include <vector>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);

        // Compute the prefix sum where prefixSum[i] holds the sum of elements from nums[0] to nums[i-1]
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        long long totalSum = prefixSum[n];
        long long validSplitCount = 0;

        // Check each position for a valid split
        for (int i = 0; i < n - 1; i++) {
            if (prefixSum[i + 1] >= (totalSum - prefixSum[i + 1])) {
                ++validSplitCount;
            }
        }

        return validSplitCount;
    }
};