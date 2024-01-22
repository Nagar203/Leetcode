from typing import *
import collections

class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        nums.sort()
        set_data = set(nums)
        missing_val = -1
        repeat_val = -1
        j = 1
        for s in set_data:
            if(j!=s):
                print("J: ",j)
                missing_val = j
                break
            j += 1

        if(missing_val == -1):
            missing_val = n
        
        for k in range(n-1):
            if(nums[k] == nums[k+1]):
                repeat_val = nums[k]
                break

        result = [repeat_val, missing_val]
        return result