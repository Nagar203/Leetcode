from typing import *

class Solution:
    t = [-1]*46
    def solve(self, n):
        if(n<1):
            return 0
        if n==1 or n==2:
            return n

        if(self.t[n]!= -1):
            return self.t[n]
        self.t[n] = self.solve(n-1) + self.solve(n-2)
        return self.t[n]

    def climbStairs(self, n: int) -> int:
        return self.solve(n)