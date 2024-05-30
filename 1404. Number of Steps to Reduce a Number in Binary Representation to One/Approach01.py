from typing import *

class Solution:
    def numSteps(self, s: str) -> int:
        result = 0
        chars = [c for c in s]

        while chars[-1] == "0":
            chars.pop()
            result += 1
        if "".join(chars) == "1":
            return result
        return result + 1 + sum(1 if c == "1" else 2 for c in chars)