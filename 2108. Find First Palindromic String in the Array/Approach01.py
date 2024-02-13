from typing import *

class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        n = len(words)

        for word in words:
            if(word == word[::-1]):
                return word
        return ""