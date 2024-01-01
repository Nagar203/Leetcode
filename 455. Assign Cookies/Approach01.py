from typing import *

class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        s.sort()
        g.sort()

        greed_len = len(g)
        cookie_size = len(s)
        i, j, result = 0, 0, 0

        while(i<greed_len and j < cookie_size):
            if(s[j] >= g[i]):
                result += 1
                j += 1
                i += 1
            else:
                j += 1

        return result
        