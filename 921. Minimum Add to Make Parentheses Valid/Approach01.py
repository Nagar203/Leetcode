from typing import *

class Solution:
    def minAddToMakeValid(self, parenthesesString):
        leftUnmatched = 0
        rightUnmatched = 0

        for currentChar in parenthesesString:
            if currentChar == '(':
                leftUnmatched += 1
            else:
                if leftUnmatched == 0:
                    rightUnmatched += 1
                else:
                    leftUnmatched -= 1

        return leftUnmatched + rightUnmatched