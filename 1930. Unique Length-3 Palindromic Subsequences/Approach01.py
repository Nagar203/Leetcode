class Solution:
    def countPalindromicSubsequence(self, inputString: str) -> int:
        stringLength = len(inputString)
        palindromicCount = 0

        # Return 0 if the string has fewer than 3 characters
        if stringLength < 3:
            return palindromicCount

        # Iterate over each possible middle character
        for middleIndex in range(26):
            middleChar = chr(middleIndex + ord('a'))  # Map index to character
            leftIndex = inputString.find(middleChar)  # First occurrence of middleChar
            rightIndex = inputString.rfind(middleChar)  # Last occurrence of middleChar

            # Check if the character forms a valid palindrome structure
            if leftIndex != -1 and rightIndex != -1 and leftIndex < rightIndex:
                uniqueCharsBetween = set(inputString[leftIndex + 1:rightIndex])  # Unique chars between left and right
                palindromicCount += len(uniqueCharsBetween)

        return palindromicCount