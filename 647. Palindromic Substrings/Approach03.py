from typing import *

class Solution:
    def __init__(self):
        self.result = 0

    def solve(self, s, i, j, n):
        while(i>=0 and j<n and s[i]==s[j]):
            self.result += 1
            i -= 1
            j += 1

    def countSubstrings(self, s: str) -> int:
        n = len(s)
        for i in range(n):
            self.solve(s, i, i, n)
            self.solve(s, i, i+1, n)
        return self.result