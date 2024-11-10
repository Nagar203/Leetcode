class Solution {
public:
    // Function to find the minimum subarray length with OR at least k
    int minimumSubarrayLength(vector<int>& nums, int targetOr) {
        constexpr int maxBits = 50;
        const int n = nums.size();
        int minLength = n + 1;
        int currentOrValue = 0;
        vector<int> bitCount(maxBits + 1);

        // Two pointers approach
        for (int left = 0, right = 0; right < n; ++right) {
            currentOrValue = computeOrValue(currentOrValue, nums[right], bitCount);

            // Try to shrink the window from the left
            while (currentOrValue >= targetOr && left <= right) {
                minLength = min(minLength, right - left + 1);
                currentOrValue = undoOrValue(currentOrValue, nums[left], bitCount);
                ++left;
            }
        }

        return (minLength == n + 1) ? -1 : minLength;
    }

private:
    static constexpr int maxBitPosition = 30;

    // Function to compute OR value after including a new number
    int computeOrValue(int currentOrValue, int num, vector<int>& bitCount) {
        for (int i = 0; i < maxBitPosition; ++i)
            if ((num >> i & 1) && ++bitCount[i] == 1)
                currentOrValue += (1 << i);
        return currentOrValue;
    }

    // Function to adjust OR value after removing a number from the left
    int undoOrValue(int currentOrValue, int num, vector<int>& bitCount) {
        for (int i = 0; i < maxBitPosition; ++i)
            if ((num >> i & 1) && --bitCount[i] == 0)
                currentOrValue -= (1 << i);
        return currentOrValue;
    }
};