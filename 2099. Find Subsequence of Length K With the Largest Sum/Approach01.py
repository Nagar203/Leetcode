class Solution:
    def maxSubsequence(self, nums: list[int], k: int) -> list[int]:
        copiedNums = nums[:]
        copiedNums.sort(reverse=True)
        threshold = copiedNums[k - 1]

        greaterCount = sum(1 for num in nums if num > threshold)
        thresholdCount = k - greaterCount

        result = []
        for num in nums:
            if num > threshold:
                result.append(num)
            elif num == threshold and thresholdCount > 0:
                result.append(num)
                thresholdCount -= 1

        return result
