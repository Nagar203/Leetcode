from typing import *
from collections import defaultdict

class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        char_cnt = defaultdict(int)
        for char in chars:
            char_cnt[char] += 1

        result = 0

        for word in words:
            if len(word) > len(chars):
                continue

            word_cnt = defaultdict(int)
            for char in word:
                word_cnt[char] += 1

            if all(word_cnt[char] <= char_cnt[char] for char in word):
                result += len(word)

        return result