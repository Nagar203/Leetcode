from typing import *

class Solution:
    def compressedString(self, inputWord: str) -> str:
        wordLength = len(inputWord)
        compressedWord = ''

        i = 0
        while i < wordLength:
            count = 0
            j = i
            while j < wordLength and inputWord[j] == inputWord[i] and count < 9:
                j += 1
                count += 1
            compressedWord += str(count) + inputWord[i]
            i = j

        return compressedWord
