class Solution {
public:
    int minimizeMax(vector<int>& nums, int requiredPairs) {
        ranges::sort(nums);
        int low = 0;
        int high = nums.back() - nums.front();

        while (low < high) {
            int mid = (low + high) / 2;
            if (countValidPairs(nums, mid) >= requiredPairs)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

private:
    int countValidPairs(const vector<int>& nums, int maxAllowedDiff) {
        int pairsFormed = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] <= maxAllowedDiff) {
                ++pairsFormed;
                ++i;
            }
        }
        return pairsFormed;
    }
};