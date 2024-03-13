from typing import *

class Solution:
    def pivotInteger(self, n: int) -> int:
        if(n==1):
            return 1
        if(n==2):
            return -1
        total = (n*(n+1))//2
        i = n//2
        
        while(i<=n):
            half_sum = (i*(i+1))//2
            rem_sum = total - half_sum
            if(rem_sum + i < half_sum):
                break
            if(rem_sum + i == half_sum):
                return i
            elif(rem_sum + i > half_sum):
                i += 1
        return -1
