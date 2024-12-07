class Solution:
    def maxCount(self, banned: list[int], n: int, maxSum: int) -> int:
        bannedSet = set(banned)
        validCount = 0
        currentSum = 0

        for currentNum in range(1, n + 1):
            if currentNum in bannedSet:
                continue

            if currentSum + currentNum <= maxSum:
                validCount += 1
                currentSum += currentNum
            else:
                break

        return validCount