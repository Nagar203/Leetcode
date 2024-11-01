from typing import *

class Solution:
    def makeFancyString(self, inputString):
        resultString = ""
        
        for currentChar in inputString:
            # Append the character if the last two characters are not the same as the current one
            if len(resultString) < 2 or resultString[-1] != currentChar or resultString[-2] != currentChar:
                resultString += currentChar
        
        return resultString