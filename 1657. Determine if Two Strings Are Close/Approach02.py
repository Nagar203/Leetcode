from typing import *
import collections

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if (len(word1) != len(word2)):
            return False

        freq_1 = {}
        freq_2 = {}

        for ch in word1:
            if ch in freq_1:
                freq_1[ch] += 1
            else:
                freq_1[ch] = 1
        
        for ch in word2:
            if ch in freq_2:
                freq_2[ch] += 1
            else:
                freq_2[ch] = 1

        key_1 = [i for i in freq_1.keys()]
        key_2 = [i for i in freq_2.keys()]
        key_1.sort()
        key_2.sort()
        if(key_1 != key_2):
            return False

        value_1 = [i for i in freq_1.values()]
        value_2 = [i for i in freq_2.values()]
        value_1.sort()
        value_2.sort()
        
        if(value_1 != value_2):
            return False

        return True