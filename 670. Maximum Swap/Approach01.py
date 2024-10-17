from typing import *

class Solution:
    def maximumSwap(self, num: int) -> int:
        numString = list(str(num))
        lastDigitIndex = [-1] * 10  # {digit: last index}

        # Record the last occurrence of each digit
        for i in range(len(numString)):
            lastDigitIndex[int(numString[i])] = i

        # Find the first opportunity to swap for maximum value
        for i in range(len(numString)):
            for d in range(9, int(numString[i]), -1):
                if lastDigitIndex[d] > i:
                    numString[i], numString[lastDigitIndex[d]] = numString[lastDigitIndex[d]], numString[i]
                    return int(''.join(numString))

        return num  # Return the original number if no swap occurs