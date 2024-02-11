from typing import *

class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        result = n
        
        for i in range(n-1):
            for j in range(i+1,n):
                sub_str = s[i:j+1]
                rev_sub_str = sub_str[::-1]
                if(sub_str == rev_sub_str):
                    result += 1
        return result