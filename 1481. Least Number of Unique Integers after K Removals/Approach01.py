from typing import *
from collections import *

class Solution:
    def findLeastNumOfUniqueInts(self, nums: List[int], k: int) -> int:
        d = collections.Counter(nums)
        n = len(d)        
        remove = 0
        d_values = [i for i in d.values()]
        d_values.sort()

        for val in d_values:
            if(k>=val):
                k = k - val
                remove += 1
            else:
                return (n-remove)
        return 0
