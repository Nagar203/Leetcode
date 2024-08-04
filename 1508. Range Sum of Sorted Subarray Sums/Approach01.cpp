#include <vector>
#include <numeric>
#include <algorithm>
#include <ranges>

using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        constexpr int kMod = 1'000'000'007;

        // Helper function to count subarrays with sums no greater than `threshold`
        // and to calculate the sum of these subarrays
        auto subarraysAndSumNoGreaterThan = [&](int threshold) -> pair<int, long> {
            int subarrayCount = 0;  // Number of subarrays with sums <= threshold
            long totalSum = 0;      // Sum of these subarrays
            int currentSum = 0;     // Current sum of the subarray
            int windowSum = 0;      // Window sum

            for (int start = 0, end = 0; end < n; ++end) {
                currentSum += nums[end] * (end - start + 1);
                windowSum += nums[end];  // Extend each subarray that ends at `end`
                while (windowSum > threshold) {
                    currentSum -= windowSum;
                    windowSum -= nums[start++];  // Shrink the window
                }
                subarrayCount += end - start + 1;
                totalSum += currentSum;
            }

            return {subarrayCount, totalSum};
        };

        // [minSum, maxSum] is the possible range of the sum of any subarray
        const int minSum = ranges::min(nums);
        const int maxSum = accumulate(nums.begin(), nums.end(), 0);

        // Helper function to find the sum of the first `k` subarrays with the smallest sums
        auto firstKSubarraysSum = [&](int k) -> long {
            int low = minSum;
            int high = maxSum;

            while (low < high) {
                const int mid = low + (high - low) / 2;
                if (subarraysAndSumNoGreaterThan(mid).first < k)
                    low = mid + 1;
                else
                    high = mid;
            }

            const auto& [count, total] = subarraysAndSumNoGreaterThan(low);
            // If `count` != `k`, there are subarrays with the same sum as `low`
            return total - low * (count - k);
        };

        return (firstKSubarraysSum(right) - firstKSubarraysSum(left - 1)) % kMod;
    }
};
