from typing import *
import collections

class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        n = len(s)
        if(n%2 !=0):
            return -1

        vowel = 'aeiouAEIOU'
        half = int(n//2)
        cnt_1, cnt_2 = 0, 0

        for i in range(half):
            if s[i] in vowel:
                cnt_1 += 1
            if s[i+half] in vowel:
                cnt_2 += 1

        return cnt_1 == cnt_2