from collections import Counter
from typing import List

class Solution:
    def checkIfExist(self, numbers: List[int]) -> bool:
        numberFrequency = Counter(numbers)

        # Check for zeroes
        if numberFrequency[0] > 1:
            return True

        # Check if double exists for any number
        for number, frequency in numberFrequency.items():
            if numberFrequency[2 * number] > 0 and number != 2 * number:
                return True

        return False