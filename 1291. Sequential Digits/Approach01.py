from typing import *

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        n_low = len(str(low))
        n_high = len(str(high))
        s = '123456789'
        result = []
        cnt = n_low

        while(cnt<=n_high):
            for i in range(10 - cnt):
                val = int(s[i:i+cnt])
                if(val<=high and val>=low):
                    result.append(val)            
            cnt += 1 
        return result        