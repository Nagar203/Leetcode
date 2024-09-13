from typing import *

class Solution:
    def xorQueries(self, inputArray, queries):
        # To store prefix XOR values
        prefixXor = [0] * (len(inputArray) + 1)
        result = []  # To store the result of each query

        # Calculate prefix XOR for the input array
        for i in range(len(inputArray)):
            prefixXor[i + 1] = prefixXor[i] ^ inputArray[i]

        # Process each query
        for query in queries:
            startIndex = query[0]
            endIndex = query[1]
            # XOR from startIndex to endIndex can be found using prefix XOR values
            result.append(prefixXor[startIndex] ^ prefixXor[endIndex + 1])

        return result