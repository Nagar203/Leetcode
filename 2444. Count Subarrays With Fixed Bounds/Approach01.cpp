class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long totalSubarrays = 0;
        int lastMinIndex = -1;
        int lastMaxIndex = -1;
        int lastInvalidIndex = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK)
                lastInvalidIndex = i;
            if (nums[i] == minK)
                lastMinIndex = i;
            if (nums[i] == maxK)
                lastMaxIndex = i;

            int validSubarrayStart = min(lastMinIndex, lastMaxIndex);
            int subarrayCount = validSubarrayStart - lastInvalidIndex;

            totalSubarrays += (subarrayCount > 0) ? subarrayCount : 0;
        }

        return totalSubarrays;
    }
};