from typing import List

class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        
        # If k is 0, return an array of zeros
        if k == 0:
            return [0] * n

        result = [0] * n
        if k > 0:
            # For positive k, sum the next k elements
            extendedCode = code + code[:k]
            for i in range(n):
                result[i] = sum(extendedCode[i + 1:i + k + 1])
        else:
            # For negative k, sum the previous k elements
            k = abs(k)
            extendedCode = code[-k:] + code
            for i in range(n):
                result[i] = sum(extendedCode[i:i + k])

        return result