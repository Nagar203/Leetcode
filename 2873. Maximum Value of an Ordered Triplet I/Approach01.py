from typing import List

class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:

        maxNumI = nums[0]  
        maxDiff = float('-inf')  
        maxTripletValue = 0  

        for j in range(1, len(nums) - 1):
            maxDiff = max(maxDiff, maxNumI - nums[j])  
            maxNumI = max(maxNumI, nums[j])  
            maxTripletValue = max(maxTripletValue, maxDiff * nums[j + 1])  

        return maxTripletValue