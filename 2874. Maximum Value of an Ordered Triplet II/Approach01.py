class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        diff = float('-inf')
        n = len(nums)
        num_i = nums[0]
        result = 0

        for index in range(1,n-1):
            diff = max(diff, num_i - nums[index])
            num_i = max(num_i, nums[index])
            result = max(result, diff*nums[index+1])
        return result