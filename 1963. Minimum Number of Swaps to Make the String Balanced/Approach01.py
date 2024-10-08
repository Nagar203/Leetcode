from typing import *

class Solution:
    def minSwaps(self, bracketString):
        # Cancel out all the matched pairs, then we'll be left with "]]]..[[[".
        # The answer is ceil(the number of unmatched pairs / 2).
        unmatchedOpenBrackets = 0

        for currentChar in bracketString:
            if currentChar == '[':
                unmatchedOpenBrackets += 1
            elif unmatchedOpenBrackets > 0:  # currentChar == ']' and there's a match.
                unmatchedOpenBrackets -= 1

        return (unmatchedOpenBrackets + 1) // 2
