from typing import *

class Solution:
    def rotateString(self, original: str, target: str) -> bool:
        if len(original) != len(target):
            return False
        doubledString = original + original
        return target in doubledString