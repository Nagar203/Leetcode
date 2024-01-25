from typing import *


class Solution:
    def __init__(self):
        self.t = [[-1] * (1002) for _ in range(1002)]
    
    def solve(self, text1, text2, i, j):
        if(i>=len(text1) or j>=len(text2)):
            return 0
        
        if(self.t[i][j]!=-1):
            return self.t[i][j]

        if(text2[j] == text1[i]):
            self.t[i][j] = 1 + self.solve(text1, text2, i+1, j+1)
            return self.t[i][j]
        else:
            self.t[i][j] =  max(self.solve(text1, text2, i+1, j), self.solve(text1, text2, i, j+1))
            return self.t[i][j]

    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        return self.solve(text1, text2, 0, 0)