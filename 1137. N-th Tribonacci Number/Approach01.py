from typing import *

class Solution:
    def tribonacci(self, n: int) -> int:
        n0, n1, n2 = 0, 1, 1

        if(n<=2):
            if(n == n0):
                return n0
            elif(n == n1):
                return n1
            else:
                return n2
        
        for i in range(3, n+1):
            total = n0 + n1 + n2
            n0 = n1
            n1 = n2
            n2 = total
        return n2