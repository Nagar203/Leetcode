class Solution:
    def canConstruct(self, inputString: str, numPalindromes: int) -> bool:
        if len(inputString) < numPalindromes:
            return False

        oddFrequencyTracker = set()

        for character in inputString:
            if character in oddFrequencyTracker:
                oddFrequencyTracker.remove(character)
            else:
                oddFrequencyTracker.add(character)
        return len(oddFrequencyTracker) <= numPalindromes
