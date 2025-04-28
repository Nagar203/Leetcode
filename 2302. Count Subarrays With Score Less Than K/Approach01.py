class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        totalSubarrays = 0
        currentSum = 0

        left = 0
        for right in range(len(nums)):
            currentSum += nums[right]
            # Shrink the window while the condition is not satisfied
            while currentSum * (right - left + 1) >= k:
                currentSum -= nums[left]
                left += 1
            # Count valid subarrays ending at current index
            totalSubarrays += right - left + 1

        return totalSubarrays
