from typing import List

class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        totalAbsoluteSum = 0  # Total absolute value sum of elements
        smallestAbsoluteValue = float('inf')  # Smallest absolute value in the matrix
        isOddNegativeCount = 0  # 0: Even number of negatives, 1: Odd number of negatives

        for row in matrix:
            for value in row:
                totalAbsoluteSum += abs(value)
                smallestAbsoluteValue = min(smallestAbsoluteValue, abs(value))
                if value < 0:
                    isOddNegativeCount ^= 1  # Toggle between 0 and 1

        # Subtract twice the smallest absolute value if the negative count is odd
        return totalAbsoluteSum - isOddNegativeCount * smallestAbsoluteValue * 2