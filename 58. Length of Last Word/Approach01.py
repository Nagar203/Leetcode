from typing import *

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        n = len(s)
        result = 0
        flag = True

        for i in range(n - 1, -1, -1):
            if s[i] != ' ':
                result += 1
                flag = False
            if s[i] == ' ' and not flag:
                return result

        return result
