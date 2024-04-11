from typing import *

class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        n = len(num)
        result = []

        for i in range(n):
            while result and result[-1] > num[i] and k > 0:
                result.pop()
                k -= 1
            if result or num[i] != '0':
                result.append(num[i])
        
        while k > 0 and result:
            result.pop()
            k -= 1
            
        if not result:
            return '0'
        
        return ''.join(result)
