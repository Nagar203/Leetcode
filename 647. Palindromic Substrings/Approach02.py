from typing import *

class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        result = 0
        t = [[False]*n for _ in range(n)]

        for L in range(1, n+1):
            for i in range(0, n):
                if(i + L - 1 < n):
                    j = i + L - 1
                    if(i==j):
                        t[i][j] = True
                    elif((i+1) == j):
                        t[i][j] = (s[i]==s[j])
                    else:
                        t[i][j] = (t[i+1][j-1] and s[i]==s[j])
                    
                    if(t[i][j]):
                        result += 1
        return result