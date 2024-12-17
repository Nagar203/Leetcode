class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        result = ""
        charFrequency = [0] * 26

        for c in s:
            charFrequency[ord(c) - ord('a')] += 1

        while True:
            isAddingSingleChar = result and self.shouldAddOne(result, charFrequency)
            largestCharIndex = self.getLargestChar(result, charFrequency)
            if largestCharIndex == -1:
                break
            numRepeats = 1 if isAddingSingleChar else min(charFrequency[largestCharIndex], repeatLimit)
            result += chr(ord('a') + largestCharIndex) * numRepeats
            charFrequency[largestCharIndex] -= numRepeats

        return result

    def shouldAddOne(self, result: str, charFrequency: list) -> bool:
        for i in range(25, -1, -1):
            if charFrequency[i]:
                return result[-1] == chr(ord('a') + i)
        return False

    def getLargestChar(self, result: str, charFrequency: list) -> int:
        for i in range(25, -1, -1):
            if charFrequency[i] and (not result or result[-1] != chr(ord('a') + i)):
                return i
        return -1