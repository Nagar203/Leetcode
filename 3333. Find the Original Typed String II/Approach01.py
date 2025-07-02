from typing import List

class Solution:
    kMod: int = 1_000_000_007

    def possibleStringCount(self, word: str, k: int) -> int:
        groups: List[int] = self.getConsecutiveLetters(word)

        totalCombinations: int = 1
        for group in groups:
            totalCombinations = (totalCombinations * group) % self.kMod
        if k <= len(groups):
            return totalCombinations

        dp: List[int] = [0] * k
        dp[0] = 1

        for i, group in enumerate(groups):
            newDp: List[int] = [0] * k
            windowSum: int = 0
            for j in range(i, k):
                newDp[j] = (newDp[j] + windowSum) % self.kMod
                windowSum = (windowSum + dp[j]) % self.kMod
                if j >= group:
                    windowSum = (windowSum - dp[j - group] + self.kMod) % self.kMod
            dp = newDp

        invalidCombinations: int = sum(dp) % self.kMod
        return (totalCombinations - invalidCombinations + self.kMod) % self.kMod

    def getConsecutiveLetters(self, word: str) -> List[int]:
        groups: List[int] = []
        group: int = 1
        for i in range(1, len(word)):
            if word[i] == word[i - 1]:
                group += 1
            else:
                groups.append(group)
                group = 1
        groups.append(group)
        return groups
