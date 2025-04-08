from typing import List

class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        totalElements = len(nums)
        
        if len(set(nums)) == totalElements:
            return 0

        operationsCount = 0
        currentIndex = 0

        while currentIndex < totalElements:
            remainingSubarray = nums[currentIndex:]
            
            if len(set(remainingSubarray)) == len(remainingSubarray):
                break
            operationsCount += 1
            currentIndex += 3  
            
        return operationsCount