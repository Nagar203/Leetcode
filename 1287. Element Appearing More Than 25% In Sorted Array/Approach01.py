from typing import *

class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n = len(arr)
        d = dict()

        for i in range(n):
            val = arr[i]

            if val in d.keys():
                d[val] = d[val] + 1
            else:
                d[val] = 1
        
        max_value = max(d.values())

        print(d)

        for key,value in d.items():
            if value == max_value:
                return key
        
        return -1
        