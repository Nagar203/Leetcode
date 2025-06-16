class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minValue = INT_MAX;
        int maxDiff = -1;

        for (int num : nums) {
            if (num > minValue)
                maxDiff = max(maxDiff, num - minValue);
            else
                minValue = num;
        }

        return maxDiff;
    }
};