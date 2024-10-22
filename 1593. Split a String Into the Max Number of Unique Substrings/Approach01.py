class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        # Use a set to track unique substrings
        return self.findMaxUniqueSplit(s, 0, set())

    def findMaxUniqueSplit(self, s: str, startIndex: int, uniqueSet: set) -> int:
        # If we have processed the entire string, return 0
        if startIndex == len(s):
            return 0

        maxUniqueParts = 0

        # Try all possible splits starting at startIndex
        for i in range(startIndex, len(s)):
            currentPart = s[startIndex:i + 1]  # Substring from startIndex to i
            if currentPart not in uniqueSet:
                uniqueSet.add(currentPart)
                # Recursively split the remaining string and count unique parts
                maxUniqueParts = max(maxUniqueParts, 1 + self.findMaxUniqueSplit(s, i + 1, uniqueSet))
                uniqueSet.remove(currentPart)

        return maxUniqueParts