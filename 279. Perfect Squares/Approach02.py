from typing import *
import sys

class Solution:
    def __init__(self):
        self.t = [-1]*10002

    def solve(self, n):
        if(n==0):
            return 0
        if(self.t[n] != -1):
            return self.t[n]
        
        result = 0
        min_cnt = sys.maxsize

        for i in range(1, int(n**(0.5))+1):
            result = 1 + self.solve(n-i*i)
            min_cnt = min(min_cnt, result);
        
        self.t[n] = min_cnt
        return self.t[n]
    
    def numSquares(self, n: int) -> int:
        output = self.solve(n)
        return output