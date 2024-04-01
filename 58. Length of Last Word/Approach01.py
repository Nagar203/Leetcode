from typing import *

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        data = s.split(" ")
        result = ''
        for word in data:
            if word != "":
                result = word
        return len(result)