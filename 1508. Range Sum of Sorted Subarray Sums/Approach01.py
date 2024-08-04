from typing import List, Tuple

class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        kMod = 1_000_000_007

        # Helper function to count subarrays with sums no greater than `threshold`
        # and to calculate the sum of these subarrays
        def subarraysAndSumNoGreaterThan(threshold: int) -> Tuple[int, int]:
            subarrayCount = 0  # Number of subarrays with sums <= threshold
            totalSum = 0  # Sum of these subarrays
            currentSum = 0  # Current sum of the subarray
            windowSum = 0  # Window sum

            start = 0
            for end in range(n):
                currentSum += nums[end] * (end - start + 1)
                windowSum += nums[end]  # Extend each subarray that ends at `end`
                while windowSum > threshold:
                    currentSum -= windowSum
                    windowSum -= nums[start]  # Shrink the window
                    start += 1
                subarrayCount += end - start + 1
                totalSum += currentSum

            return subarrayCount, totalSum

        # [minSum, maxSum] is the possible range of the sum of any subarray
        minSum = min(nums)
        maxSum = sum(nums)

        # Helper function to find the sum of the first `k` subarrays with the smallest sums
        def firstKSubarraysSum(k: int) -> int:
            low = minSum
            high = maxSum

            while low < high:
                mid = low + (high - low) // 2
                if subarraysAndSumNoGreaterThan(mid)[0] < k:
                    low = mid + 1
                else:
                    high = mid

            count, total = subarraysAndSumNoGreaterThan(low)
            # If `count` != `k`, there are subarrays with the same sum as `low`
            return total - low * (count - k)

        return (firstKSubarraysSum(right) - firstKSubarraysSum(left - 1)) % kMod
