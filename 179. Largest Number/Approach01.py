from typing import *

class Solution:
    def largestNumber(self, numbers: List[int]) -> str:
        # Sort the numbers based on custom comparison logic
        numbers = sorted(numbers, key=lambda num: str(num) * 10, reverse=True)

        # Concatenate sorted numbers into the result string
        result = ''.join(map(str, numbers))

        # If the largest number starts with '0', return "0"
        return result if result[0] != '0' else "0"