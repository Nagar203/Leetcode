from typing import *

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        uglyNumbers = [1]  # List to store ugly numbers
        index2 = 0  # Pointer for multiples of 2
        index3 = 0  # Pointer for multiples of 3
        index5 = 0  # Pointer for multiples of 5

        while len(uglyNumbers) < n:
            nextMultipleOf2 = uglyNumbers[index2] * 2
            nextMultipleOf3 = uglyNumbers[index3] * 3
            nextMultipleOf5 = uglyNumbers[index5] * 5
            nextUglyNumber = min(nextMultipleOf2, nextMultipleOf3, nextMultipleOf5)
            
            if nextUglyNumber == nextMultipleOf2:
                index2 += 1
            if nextUglyNumber == nextMultipleOf3:
                index3 += 1
            if nextUglyNumber == nextMultipleOf5:
                index5 += 1
                
            uglyNumbers.append(nextUglyNumber)

        return uglyNumbers[-1]  # Return the nth ugly number
