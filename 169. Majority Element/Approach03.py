from typing import *

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        result = nums[0]
        cnt = 1

        for i in range(1,n):
            if(cnt==0):
                result = nums[i]
            if(nums[i]==result):
                cnt += 1
            elif(nums[i] != result):
                cnt -= 1
        return result