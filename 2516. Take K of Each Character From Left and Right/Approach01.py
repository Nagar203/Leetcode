class Solution:
    def takeCharacters(self, inputString: str, minFrequency: int) -> int:
        stringLength = len(inputString)
        minDeletions = stringLength
        characterCount = [0] * 3

        # Count the frequency of each character
        for character in inputString:
            characterCount[ord(character) - ord('a')] += 1

        # If any character's frequency is less than minFrequency, return -1
        if any(count < minFrequency for count in characterCount):
            return -1

        # Sliding window to find the minimum substring length
        leftIndex = 0
        for rightIndex in range(stringLength):
            characterCount[ord(inputString[rightIndex]) - ord('a')] -= 1
            while characterCount[ord(inputString[rightIndex]) - ord('a')] < minFrequency:
                characterCount[ord(inputString[leftIndex]) - ord('a')] += 1
                leftIndex += 1
            minDeletions = min(minDeletions, stringLength - (rightIndex - leftIndex + 1))

        return minDeletions