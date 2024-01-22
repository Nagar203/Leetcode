from typing import *
import collections

class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        d = collections.Counter(nums)
        missing_val = -1
        repeat_val = -1

        for key, val in d.items():
            if val==2:
                repeat_val = key
                break

        j = 1
        d = dict(sorted(d.items()))
        for key in d.keys():
            if(j!=key):
                print(j)
                missing_val = j
                break
            j += 1

        if(missing_val == -1):
            missing_val = n

        return [repeat_val, missing_val]