from typing import *

class Solution:
    def checkValidString(self, s: str) -> bool:
        n = len(s)
        t = [[False]*102 for _ in range(102)]
        t[n][0] = True

        for index in range(n - 1, -1, -1): 
            for open in range(n + 1):
                is_valid = False
                
                if s[index] == '*':
                    is_valid |= t[index + 1][open + 1]
                    is_valid |= t[index + 1][open]
                    if open > 0:
                        is_valid |= t[index + 1][open - 1]
                elif s[index] == '(':
                    is_valid |= t[index + 1][open + 1]
                elif open > 0:
                    is_valid |= t[index + 1][open - 1]

                t[index][open] = is_valid

        return t[0][0]
