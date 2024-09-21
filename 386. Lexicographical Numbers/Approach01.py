from typing import *

class Solution:
    def lexicalOrder(self, maxNumber: int) -> list[int]:
        result = []
        currentNumber = 1

        # Generate numbers in lexicographical order
        while len(result) < maxNumber:
            result.append(currentNumber)
            if currentNumber * 10 <= maxNumber:
                currentNumber *= 10
            else:
                while currentNumber % 10 == 9 or currentNumber == maxNumber:
                    currentNumber //= 10
                currentNumber += 1

        return result