class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        const int maxOrValue = accumulate(nums.begin(), nums.end(), 0, bit_or<>());
        int subsetCount = 0;
        dfs(nums, 0, 0, maxOrValue, subsetCount);
        return subsetCount;
    }

private:
    void dfs(const vector<int>& nums, int index, int currentOrValue, const int& maxOrValue, int& subsetCount) {
        if (index == nums.size()) {
            if (currentOrValue == maxOrValue)
                ++subsetCount;
            return;
        }

        dfs(nums, index + 1, currentOrValue, maxOrValue, subsetCount);
        dfs(nums, index + 1, currentOrValue | nums[index], maxOrValue, subsetCount);
    }
};