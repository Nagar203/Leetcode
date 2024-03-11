from typing import *
import collections

class Solution:
    def customSortString(self, order: str, s: str) -> str:
        result = ''
        temp = ''
        temp_result = ''
        d = collections.Counter(s)
        for ch in order:
            if(ch in s):
                temp += ch*(d[ch])
        for ch in s:
            if(ch not in temp):
                result += ch

        temp = temp + result
        return temp