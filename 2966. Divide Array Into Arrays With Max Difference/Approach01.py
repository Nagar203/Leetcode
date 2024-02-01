from typing import *

class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        n = len(nums)
        
        if(n%3 != 0):
            return []
        
        nums.sort()
        result = []
        
        print(nums)
        for i in range(0,n,3):            
            if ((nums[i+1] - nums[i]) > k) or ((nums[i+2] - nums[i+1]) > k) or ((nums[i+2] - nums[i]) > k):
                return []
            result.append(nums[i:i+3])

        return result