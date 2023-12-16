from typing import *

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        original_string = ''.join(sorted(s))
        match_string = ''.join(sorted(t))

        if(original_string == match_string):
            return True
        return False