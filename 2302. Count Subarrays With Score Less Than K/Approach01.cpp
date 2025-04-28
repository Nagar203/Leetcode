class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long totalSubarrays = 0;
        long long currentSum = 0;

        for (int left = 0, right = 0; right < nums.size(); ++right) {
            currentSum += nums[right];
            // Shrink the window while the condition is not satisfied
            while (currentSum * (right - left + 1) >= k)
                currentSum -= nums[left++];
            // Count valid subarrays ending at current index
            totalSubarrays += right - left + 1;
        }

        return totalSubarrays;
    }
};
