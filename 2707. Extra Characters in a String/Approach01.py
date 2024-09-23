from typing import *

class Solution:
    def minExtraChar(self, string: str, wordList: List[str]) -> int:
        stringLength = len(string)
        wordSet = set(wordList)
        dpArray = [0] * (stringLength + 1)

        for i in range(1, stringLength + 1):
            dpArray[i] = dpArray[i - 1] + 1
            for j in range(i):
                if string[j:i] in wordSet:
                    dpArray[i] = min(dpArray[i], dpArray[j])

        return dpArray[stringLength]