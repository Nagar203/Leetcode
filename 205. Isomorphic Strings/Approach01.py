from typing import *

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        n1 = len(s)
        n2 = len(t)
        if(len(set(s))!=len(set(t))):
            return False
        f1 = {}
        f2 = {}
        mapping = {}

        for i in range(0,n2):
            mapping[s[i]] = t[i]

        for i in range(0,n2):
            if(f1.get(s[i])==None):
                f1[s[i]] = 1
            else:
                f1[s[i]] += 1
            
            if(f2.get(t[i])==None):
                f2[t[i]] = 1
            else:
                f2[t[i]] += 1
            
            if(f1[s[i]] != f2[t[i]] or mapping[s[i]] != t[i]):
                return False

        print(f1)
        print(f2)
        return True