from typing import *

class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        index = word.find(ch)

        rev_data = word[:index+1]
        rem_data = word[index+1:]
        rev_data = rev_data[::-1]
        result = rev_data + rem_data
        return result