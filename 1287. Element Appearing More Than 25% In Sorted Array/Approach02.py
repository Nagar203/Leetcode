from typing import *

class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        result = len(arr)//4

        for i in range(len(arr)-result):
            if(arr[i] == arr[i+result]):
                return arr[i]
        return -1