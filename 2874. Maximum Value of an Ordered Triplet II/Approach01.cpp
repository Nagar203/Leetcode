class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result = 0;
        int num_i = nums[0];
        int diff = INT_MIN;

        for (int index = 1; index < nums.size() - 1; ++index) {
            diff = max(diff, num_i - nums[index]);
            num_i = max(num_i, nums[index]);
            result = max(result, static_cast<long long>(diff) * nums[index + 1]);
        }
        return result;
    }
};