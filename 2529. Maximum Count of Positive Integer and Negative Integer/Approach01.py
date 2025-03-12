class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        negCount = 0
        result = 0
        zeros = 0
        for num in nums:
            if num < 0:
                negCount += 1
            if(num==0):
                zeros+=1
        result = max(len(nums) - zeros - negCount, negCount)
        return result