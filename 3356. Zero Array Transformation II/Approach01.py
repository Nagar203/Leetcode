from typing import List
class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        diffArray = [0] * (len(nums) + 1)  
        currentSum = 0  
        queryIndex = 0  
        for i in range(len(nums)):
            while currentSum + diffArray[i] < nums[i]:
                if queryIndex == len(queries):
                    return -1  
                left, right, incrementValue = queries[queryIndex]
                queryIndex += 1
                if right < i:
                    continue  
                diffArray[max(left, i)] += incrementValue
                diffArray[right + 1] -= incrementValue
            currentSum += diffArray[i]  
        return queryIndex