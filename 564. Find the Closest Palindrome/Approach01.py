from typing import *

class Solution:
    def nearestPalindromic(self, number: str) -> str:
        previousPalindrome, nextPalindrome = self.getClosestPalindromes(number)
        return str(previousPalindrome) if abs(previousPalindrome - int(number)) <= abs(nextPalindrome - int(number)) else str(nextPalindrome)

    def getClosestPalindromes(self, number: str) -> (int, int):
        originalNumber = int(number)
        length = len(number)
        closestPalindromes = (0, 0)
        halfNumber = number[:(length + 1) // 2]
        reversedHalfNumber = self.reverseString(halfNumber[:length // 2])
        candidatePalindrome = int(halfNumber + reversedHalfNumber)

        if candidatePalindrome < originalNumber:
            closestPalindromes = (candidatePalindrome, closestPalindromes[1])
        else:
            previousHalf = str(int(halfNumber) - 1)
            reversedPreviousHalf = self.reverseString(previousHalf[:length // 2])
            if length % 2 == 0 and int(previousHalf) == 0:
                closestPalindromes = (9, closestPalindromes[1])
            elif length % 2 == 0 and previousHalf == "9":
                closestPalindromes = (int(previousHalf + '9' + reversedPreviousHalf), closestPalindromes[1])
            else:
                closestPalindromes = (int(previousHalf + reversedPreviousHalf), closestPalindromes[1])

        if candidatePalindrome > originalNumber:
            closestPalindromes = (closestPalindromes[0], candidatePalindrome)
        else:
            nextHalf = str(int(halfNumber) + 1)
            reversedNextHalf = self.reverseString(nextHalf[:length // 2])
            closestPalindromes = (closestPalindromes[0], int(nextHalf + reversedNextHalf))

        return closestPalindromes

    def reverseString(self, s: str) -> str:
        return s[::-1]