from typing import *
from collections import *

class Solution:
    def frequencySort(self, s: str) -> str:
        if(len(s)==0):
            return ''
        f = collections.Counter(s)
        data = []

        for key, val in f.items():
            data.append([val*(-1), key])

        data.sort()
        result = ''

        for d in data:
            result += d[1]*(d[0]*(-1))

        return result

