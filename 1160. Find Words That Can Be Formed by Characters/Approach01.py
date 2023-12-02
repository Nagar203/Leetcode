from typing import List
from collections import Counter


class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        char_cnt = Counter(chars)
        result = 0

        for word in words:
            word_cnt = Counter(word)
            if all(word_cnt[char] <= char_cnt[char] for char in word_cnt):
                result += len(word)

        return result