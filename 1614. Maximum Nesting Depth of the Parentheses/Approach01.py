from typing import *

class Solution:
    def maxDepth(self, s: str) -> int:
        result = 0
        cnt_open = 0

        for ch in s:
            if(ch == '('):
                cnt_open += 1
            elif(ch == ')'):
                cnt_open -= 1
            result = max(result, cnt_open)
        
        return result