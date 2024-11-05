from typing import *

class Solution:
    def minChanges(self, inputString: str) -> int:
        changeCount = 0

        for index in range(0, len(inputString) - 1, 2):
            if inputString[index] != inputString[index + 1]:
                changeCount += 1

        return changeCount