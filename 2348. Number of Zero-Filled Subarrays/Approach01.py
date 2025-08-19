class Solution:
    def zeroFilledSubarray(self, nums: list[int]) -> int:
        currentZeroCount = 0
        totalSubarrays = 0
        for num in nums:
            if num == 0:
                currentZeroCount += 1            # extend zero sequence
                totalSubarrays += currentZeroCount  # add new subarrays ending here
            else:
                currentZeroCount = 0  # reset when non-zero encountered
        return totalSubarrays
