class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ranges::sort(nums);  // Sort the array for two-pointer traversal
        return countLessThanOrEqual(nums, upper) - countLessThanOrEqual(nums, lower - 1);
    }

private:
    long countLessThanOrEqual(const vector<int>& nums, int maxSum) {
        long totalPairs = 0;
        int leftPointer = 0;
        int rightPointer = nums.size() - 1;
        while (leftPointer < rightPointer) {
            while (leftPointer < rightPointer && nums[leftPointer] + nums[rightPointer] > maxSum)
                --rightPointer;
            totalPairs += rightPointer - leftPointer;
            ++leftPointer;
        }
        return totalPairs;
    }
};
