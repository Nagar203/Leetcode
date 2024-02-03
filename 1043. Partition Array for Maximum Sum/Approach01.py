from typing import *

class Solution:
    def __init__(self):
        self.t = [-1]*501

    def solve(self, i, arr, k, n):
        if(i>=n):
            return 0
        if(self.t[i] != -1):
            return self.t[i]
        result = 0
        max_val = -1
        j = i
        while(j<n and (j-i+1 <= k)):
            max_val = max(max_val, arr[j])
            result = max(result, (j-i+1)*max_val + self.solve(j+1, arr, k, n))
            j += 1
        self.t[i] = result
        return self.t[i]

    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        result = self.solve(0, arr, k, n)
        return result    