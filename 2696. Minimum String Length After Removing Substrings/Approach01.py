from typing import *

class Solution:
    def minLength(self, inputString):
        charStack = []

        for currentChar in inputString:
            if currentChar == 'B' and self.isMatchingPair(charStack, 'A'):
                charStack.pop()
            elif currentChar == 'D' and self.isMatchingPair(charStack, 'C'):
                charStack.pop()
            else:
                charStack.append(currentChar)

        return len(charStack)

    def isMatchingPair(self, charStack, comparisonChar):
        return charStack and charStack[-1] == comparisonChar
