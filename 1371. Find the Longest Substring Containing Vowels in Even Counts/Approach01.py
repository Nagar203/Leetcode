from typing import *

class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        vowels = "aeiou"
        maxLength = 0
        binaryPrefix = 0  # The binary representation of vowel counts
        prefixToIndex = {0: -1}  # Stores the first occurrence of each binary prefix

        # Iterate through the string
        for i, char in enumerate(s):
            vowelIndex = vowels.find(char)
            # If the current character is a vowel, update the binary prefix
            if vowelIndex != -1:
                binaryPrefix ^= 1 << vowelIndex
            # If the binary prefix hasn't been seen before, record its index
            if binaryPrefix not in prefixToIndex:
                prefixToIndex[binaryPrefix] = i
            # Calculate the length of the current substring
            maxLength = max(maxLength, i - prefixToIndex[binaryPrefix])

        return maxLength