from itertools import accumulate

class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        totalSum = sum(nums)
        remainder = totalSum % p
        if remainder == 0:
            return 0

        prefixToIndex = {0: -1}
        minLength = len(nums)
        prefixSum = 0

        for i, num in enumerate(nums):
            prefixSum += num
            prefixSum %= p
            target = (prefixSum - remainder + p) % p
            if target in prefixToIndex:
                minLength = min(minLength, i - prefixToIndex[target])
            prefixToIndex[prefixSum] = i

        return -1 if minLength == len(nums) else minLength