from typing import *

class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        cnt = s.count('1')
        n = len(s)
        result = '1'*(cnt-1) + '0'*(n-cnt) + '1'
        return result