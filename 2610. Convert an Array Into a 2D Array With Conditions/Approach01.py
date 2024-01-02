from typing import *

class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        result = []
        count = [0] * (len(nums) + 1)

        for num in nums:
            count[num] += 1
    
            if count[num] > len(result):
                result.append([])
    
            result[count[num] - 1].append(num)

        return result