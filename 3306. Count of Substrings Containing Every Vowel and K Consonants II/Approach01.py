from collections import defaultdict

class Solution:
    def countOfSubstrings(self, word: str, maxNonVowel: int) -> int:
        return (self._countSubstringsWithAtMost(word, maxNonVowel) - 
                self._countSubstringsWithAtMost(word, maxNonVowel - 1))

    def _countSubstringsWithAtMost(self, word: str, maxNonVowel: int) -> int:
        if maxNonVowel == -1:
            return 0

        substringCount = 0
        vowelCount = 0
        uniqueVowelCount = 0
        lastVowelPosition = {}

        left = 0
        for right in range(len(word)):
            if self._isVowel(word[right]):
                vowelCount += 1
                if word[right] not in lastVowelPosition or lastVowelPosition[word[right]] < left:
                    uniqueVowelCount += 1
                lastVowelPosition[word[right]] = right

            while right - left + 1 - vowelCount > maxNonVowel:
                if self._isVowel(word[left]):
                    vowelCount -= 1
                    if lastVowelPosition[word[left]] == left:
                        uniqueVowelCount -= 1
                left += 1

            if uniqueVowelCount == 5:
                substringCount += min(
                    lastVowelPosition.get('a', float('inf')),
                    lastVowelPosition.get('e', float('inf')),
                    lastVowelPosition.get('i', float('inf')),
                    lastVowelPosition.get('o', float('inf')),
                    lastVowelPosition.get('u', float('inf'))
                ) - left + 1

        return substringCount

    def _isVowel(self, character: str) -> bool:
        return character in "aeiou"