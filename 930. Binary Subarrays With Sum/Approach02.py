from typing import *
import collections

class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        n = len(nums)
        i, j = 0, 0
        result = 0
        window_sum = 0
        cnt_zeros = 0

        while(j<n):
            window_sum += nums[j]
            while(i<j and (nums[i]==0 or window_sum > goal)):
                if(nums[i]==0):
                    cnt_zeros += 1
                else:
                    cnt_zeros = 0
                window_sum -= nums[i]
                i += 1
            if(window_sum == goal):
                result = result + cnt_zeros + 1
            j += 1
        return result