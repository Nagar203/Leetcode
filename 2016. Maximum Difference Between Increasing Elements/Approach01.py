class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        minValue = float('inf')
        maxDiff = -1

        for num in nums:
            if num > minValue:
                maxDiff = max(maxDiff, num - minValue)
            else:
                minValue = num

        return maxDiff
