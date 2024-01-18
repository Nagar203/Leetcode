from typing import *
import collections

class Solution:
    def climbStairs(self, n: int) -> int:
        t = [0]*46
        t[1] = 1
        t[2] = 2

        if(n==1 or n==2):
            return n

        for i in range(3,n+1):
            t[i] = t[i-1] + t[i-2]

        return t[n]