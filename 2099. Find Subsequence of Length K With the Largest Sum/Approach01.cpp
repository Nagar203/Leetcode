class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> result;
        vector<int> copiedNums(nums);

        nth_element(copiedNums.begin(), copiedNums.end() - k, copiedNums.end());
        int threshold = copiedNums[copiedNums.size() - k];

        int greaterCount = ranges::count_if(nums, [&](int num) { return num > threshold; });
        int thresholdCount = k - greaterCount;

        for (int num : nums) {
            if (num > threshold) {
                result.push_back(num);
            } else if (num == threshold && thresholdCount > 0) {
                result.push_back(num);
                --thresholdCount;
            }
        }

        return result;
    }
};
