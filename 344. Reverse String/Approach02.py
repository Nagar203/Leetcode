from typing import *

class Solution:
    def reverseString(self, s: List[str]) -> None:
        i = 0
        j = len(s)

        for i in range(j//2):
            s[i], s[j-1] = s[j-1], s[i]
            j -= 1