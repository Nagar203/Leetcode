from collections import Counter
from typing import List

class Solution:
    def addSpaces(self, string: str, spaces: List[int]) -> str:
        charIndex = 0
        resultString = ''
        spaceMap = Counter(spaces)
        
        for character in string:
            if spaceMap[charIndex] > 0:
                resultString += ' '
            resultString += character
            charIndex += 1
        
        return resultString