from typing import *

class Solution:
    def findKthNumber(self, totalNumbers: int, k: int) -> int:
        currentNumber = 1  # The number we are searching for
        currentPosition = 1  # Position counter
        
        # Iterate to find the kth number
        while currentPosition < k:
            gap = self.calculateGap(currentNumber, currentNumber + 1, totalNumbers)
            
            # Check if the kth number is within this gap
            if currentPosition + gap <= k:
                currentPosition += gap
                currentNumber += 1  # Move to the next number
            else:
                currentPosition += 1
                currentNumber *= 10  # Move to the next level in lexicographical order
        
        return currentNumber

    # Function to calculate the gap between two numbers in lexicographical order
    def calculateGap(self, start: int, end: int, maxNumber: int) -> int:
        gap = 0
        
        # Calculate gap between 'start' and 'end' until 'maxNumber'
        while start <= maxNumber:
            gap += min(maxNumber + 1, end) - start
            start *= 10
            end *= 10
        
        return gap