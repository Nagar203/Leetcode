from typing import *

class Solution:
    def checkInclusion(self, pattern: str, text: str) -> bool:
        charFrequency = [0] * 26
        remainingChars = len(pattern)

        # Fill charFrequency with the frequency of characters in the pattern
        for ch in pattern:
            charFrequency[ord(ch) - ord('a')] += 1

        left = 0
        for right in range(len(text)):
            # Decrement the count for the current character
            if charFrequency[ord(text[right]) - ord('a')] > 0:
                remainingChars -= 1
            charFrequency[ord(text[right]) - ord('a')] -= 1

            # If all characters match, return True
            if remainingChars == 0:
                return True

            # Maintain the window size equal to the length of the pattern
            if right - left + 1 >= len(pattern):
                # Restore the count of the left character if it's part of the pattern
                if charFrequency[ord(text[left]) - ord('a')] >= 0:
                    remainingChars += 1
                charFrequency[ord(text[left]) - ord('a')] += 1
                left += 1

        return False