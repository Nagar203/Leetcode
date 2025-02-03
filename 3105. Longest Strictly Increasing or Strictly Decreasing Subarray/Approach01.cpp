class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLength = 1;
        int increasingLength = 1;
        int decreasingLength = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                increasingLength += 1;
                decreasingLength = 1;
            } else if (nums[i] < nums[i - 1]) {
                decreasingLength += 1;
                increasingLength = 1;
            } else {
                increasingLength = 1;
                decreasingLength = 1;
            }
            maxLength = max({maxLength, increasingLength, decreasingLength});
        }

        return maxLength;
    }
};
