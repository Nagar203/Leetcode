from typing import *

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if(n<=0):
            return False
        cnt = 0
        for i in range(31):
            if(n&1):
                cnt += 1
            n >>= 1
        return True if(cnt==1) else False
        