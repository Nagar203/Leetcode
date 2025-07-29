class Solution:
    def smallestSubarrays(self, nums):
        maxBit = 30
        result = [1] * len(nums)
        lastSeenBitIndex = [0] * maxBit

        for currentIndex in range(len(nums) - 1, -1, -1):
            for bit in range(maxBit):
                if (nums[currentIndex] >> bit) & 1:
                    lastSeenBitIndex[bit] = currentIndex
                result[currentIndex] = max(result[currentIndex], lastSeenBitIndex[bit] - currentIndex + 1)
        return result
