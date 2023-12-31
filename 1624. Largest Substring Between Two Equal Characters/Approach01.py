from typing import *

class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        result = -1
        for i in range(len(s)):
            for j in range(len(s)-1, 0, -1):
                if(s[i] == s[j] and result < j - i -1):
                    result = j - i -1

        return result