class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k--) {
            int minIndex = 0;
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] < nums[minIndex]) {
                    minIndex = i;
                }
            }
            nums[minIndex] *= multiplier;
        }
        return nums;
    }
};