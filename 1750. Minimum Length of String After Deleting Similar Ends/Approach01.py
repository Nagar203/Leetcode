from typing import *

class Solution:
    def minimumLength(self, s: str) -> int:
        n = len(s)
        i, j = 0, n-1
        while(i<j and s[i]==s[j]):
            current = s[i]
            while(i<j and current == s[i]):
                i += 1
            while(i<=j and current == s[j]):
                j -= 1
        return (j-i+1)
