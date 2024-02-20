from typing import *

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if(n<=0):
            return False
        cnt = 0
        while(n):
            if(n&1):
                cnt += 1
            n = n>>1
            if(cnt==2):
                return False
        return True
        