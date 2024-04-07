from typing import *

class Solution:
    def __init__(self) -> None:
        self.t = [[-1]*101 for i in range(101)]

    def solve(self, index, open, s, n):
        if(index == n):
            return open == 0
        
        if(self.t[index][open]!= -1):
            return self.t[index][open]
        
        is_valid = False
        
        if(s[index] == '*'):
            is_valid |= self.solve(index + 1, open + 1, s, n)
            is_valid |= self.solve(index + 1, open, s, n)
            if(open>0):
                is_valid |= self.solve(index + 1, open - 1, s, n)
        elif(s[index]=='('):
            is_valid |= self.solve(index + 1, open + 1, s, n)
        elif(open > 0):
            is_valid |= self.solve(index + 1, open - 1, s, n)
        self.t[index][open] = is_valid
        return is_valid
    
    def checkValidString(self, s: str) -> bool:
        n = len(s)
        result = self.solve(0, 0, s, n)
        return result