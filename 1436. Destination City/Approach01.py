from typing import *

class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        row = len(paths)
        d = dict()
        result = []
        for i in range(row):
            if paths[i][0] in d.keys():
                d[paths[i][0]] += 1
            else:
                d[paths[i][0]] = 1
            if paths[i][1] in d.keys():
                d[paths[i][1]]  += 1
            else:
                d[paths[i][1]] = 1

        for key,val in d.items():
            if(val == 1):
                result.append(key)

        for i in range(row):
            if(result[0] in paths[i][0]):
                return result[1]

        return result[0]
