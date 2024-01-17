from typing import *
import collections

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        data = {}
        
        for i in arr:
            if(i in data):
                data[i] += 1
            else:
                data[i] = 1
        
        # data = collections.Counter(arr)  # this line create hashmap (frequency)

        values = [i for i in data.values()]
        n = len(data)
        return len(set(values)) == n