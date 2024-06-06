from typing import *
from typing import List

class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        result = []
        commonCount = [float('inf')] * 26

        for word in words:
            count = [0] * 26
            for c in word:
                count[ord(c) - ord('a')] += 1
            for i in range(26):
                commonCount[i] = min(commonCount[i], count[i])

        for i in range(26):
            result.extend([chr(i + ord('a'))] * commonCount[i])

        return result
