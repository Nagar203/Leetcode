from typing import *

class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        result = 0
        
        for word in words:
            flag = 1
            for ch in word:
                if ch not in allowed:
                    flag = 0
                    break

            if flag:
                result += 1

        return result