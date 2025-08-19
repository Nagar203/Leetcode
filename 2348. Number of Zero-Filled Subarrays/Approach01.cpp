class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long currentZeroCount = 0, totalSubarrays = 0;
        for (int num : nums) {
            if (num == 0) {
                currentZeroCount++;              // extend zero sequence
                totalSubarrays += currentZeroCount; // add new subarrays ending here
            } else {
                currentZeroCount = 0; // reset when non-zero encountered
            }
        }
        return totalSubarrays;
    }
};
