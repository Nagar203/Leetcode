from typing import *

class Solution:
    def minEnd(self, numBits, inputNum):
        # Calculate maximum bits needed based on the inputs
        maxBits = int(log2(numBits) + log2(inputNum) + 2)
        targetValue = numBits - 1
        resultNum = inputNum
        bitIndex = 0

        # Iterate through each bit up to maxBits
        for i in range(maxBits):
            # Check if the current bit of resultNum is 0
            if (resultNum >> i & 1) == 0:
                # If the corresponding bit in targetValue is 1, set it in resultNum
                if (targetValue >> bitIndex & 1):
                    resultNum |= 1 << i
                bitIndex += 1

        return resultNum