from typing import *

class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        n = len(words)
        string = ''.join(words)
        new_str = sorted(string)
        str_len = len(new_str)

        if(n==1):
            return True
        
        if(str_len%n != 0):
            return False

        d = dict()

        for i in range(str_len):
            if d.get(new_str[i]) != None:
                d[new_str[i]] += 1
            else:
                d[new_str[i]] = 1

        for val in d.values():
            if(val%n != 0):
                return False

        return True