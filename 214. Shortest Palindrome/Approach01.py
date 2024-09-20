from typing import *

class Solution:
    def shortestPalindrome(self, inputString: str) -> str:
        reversedString = inputString[::-1]
        
        # Find the longest palindromic prefix
        for i in range(len(inputString)):
            if inputString[:len(inputString) - i] == reversedString[i:]:
                return reversedString[:i] + inputString
        
        return reversedString + inputString