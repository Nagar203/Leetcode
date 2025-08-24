class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLength = 0;
        int zeroCount = 0;

        for (int left = 0, right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0)
                ++zeroCount;

            while (zeroCount == 2) {
                if (nums[left++] == 0)
                    --zeroCount;
            }

            maxLength = max(maxLength, right - left);
        }

        return maxLength;
    }
};
