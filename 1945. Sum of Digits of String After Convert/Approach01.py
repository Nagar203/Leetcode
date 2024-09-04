from typing import *

class Solution:
    def getLucky(self, s: str, k: int) -> int:
        numericString = ''
        
        # Convert each character in the input string to its numeric equivalent
        for char in s:
            numericValue = ord(char) - ord('a') + 1
            numericString += str(numericValue)
        
        # Sum the digits for k iterations
        for _ in range(k):
            digitSum = sum(int(digit) for digit in numericString)
            numericString = str(digitSum)
        
        return int(numericString)