import string

class Solution:
    def canMakeSubsequence(self, sourceString: str, targetString: str) -> bool:
        targetIndex = 0  # Index for targetString

        for sourceChar in sourceString:
            # Check if the current character matches or can rotate to match
            if (sourceChar == targetString[targetIndex] or 
                chr(ord('a') + (string.ascii_lowercase.index(sourceChar) + 1) % 26) == targetString[targetIndex]):
                targetIndex += 1
                if targetIndex == len(targetString):
                    return True

        return False