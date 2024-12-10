class Solution:
    def maximumLength(self, s: str) -> int:
        stringLength = len(s)
        maxLength = -1
        currentLength = 0
        previousChar = '@'
        # charFrequency[charIndex][repetition] := frequency of ('a' + charIndex) repeating `repetition` times
        charFrequency = [[0] * (stringLength + 1) for _ in range(26)]

        for currentChar in s:
            if currentChar == previousChar:
                currentLength += 1
                charFrequency[ord(currentChar) - ord('a')][currentLength] += 1
            else:
                currentLength = 1
                charFrequency[ord(currentChar) - ord('a')][currentLength] += 1
                previousChar = currentChar

        for frequency in charFrequency:
            maxLength = max(maxLength, self.getMaxFreq(frequency, stringLength))

        return maxLength

    # Returns the maximum frequency that occurs more than three times.
    def getMaxFreq(self, frequency: list[int], maxFrequency: int) -> int:
        occurrences = 0
        for freq in range(maxFrequency, 0, -1):
            occurrences += frequency[freq]
            if occurrences >= 3:
                return freq
        return -1