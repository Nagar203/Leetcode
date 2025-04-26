class Solution:
    def countSubarrays(self, nums, minK, maxK):
        totalSubarrays = 0
        lastMinIndex = -1
        lastMaxIndex = -1
        lastInvalidIndex = -1

        for i in range(len(nums)):
            if nums[i] < minK or nums[i] > maxK:
                lastInvalidIndex = i
            if nums[i] == minK:
                lastMinIndex = i
            if nums[i] == maxK:
                lastMaxIndex = i

            validSubarrayStart = min(lastMinIndex, lastMaxIndex)
            subarrayCount = validSubarrayStart - lastInvalidIndex

            totalSubarrays += subarrayCount if subarrayCount > 0 else 0

        return totalSubarrays