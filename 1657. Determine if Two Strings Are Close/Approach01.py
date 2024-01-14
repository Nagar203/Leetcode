from typing import *
import collections

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if (len(word1) != len(word2)):
            return False
        
        set1 = set(sorted(word1))
        set2 = set(sorted(word2))

        if set1 != set2:
            return False

        freq_1 = {}
        freq_2 = {}

        for s in set1:
            freq_1[s] = word1.count(s)
        for s in set2:
            freq_2[s] = word2.count(s)

        value_1 = [i for i in freq_1.values()]
        value_2 = [i for i in freq_2.values()]
        value_1.sort()
        value_2.sort()
        
        if(value_1 != value_2):
            return False

        return True