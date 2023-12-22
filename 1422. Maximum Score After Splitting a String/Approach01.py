from typing import *

class Solution:
    def maxScore(self, s: str) -> int:
        one_cnt = s.count('1')
        zero_cnt = 0
        result = -1

        for i in range(len(s)-1):
            if(s[i] == '0'):
                zero_cnt += 1
            else:
                one_cnt -= 1
            if(result < (zero_cnt + one_cnt)):
                result = zero_cnt + one_cnt

        return result