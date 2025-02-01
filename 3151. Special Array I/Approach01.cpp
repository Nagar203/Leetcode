class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int size = nums.size();

        if (size == 1) {
            return true;
        }

        for (int i = 1; i < size; ++i) {
            // Check if two consecutive numbers have the same parity
            if ((nums[i] & 1) == (nums[i - 1] & 1)) {
                return false;
            }
        }
        return true;
    }
};