from collections import Counter

class Solution:
    def minimumPushes(self, word: str) -> int:
        wordLength = len(word)
        numUniqueChars = len(set(word))
        charFrequency = Counter(word)
        
        # If there are 8 or fewer unique characters, return the total number of characters
        if numUniqueChars <= 8:
            totalPushes = sum(charFrequency.values())
            return totalPushes
        
        position = 1
        totalPushes = 0

        # Get frequencies of characters sorted in descending order
        sortedFrequencies = sorted(charFrequency.values(), reverse=True)
        
        # Calculate the total number of pushes based on the position of each character
        for frequency in sortedFrequencies:
            if position <= 8:
                totalPushes += frequency
            elif 9 <= position <= 16:
                totalPushes += frequency * 2
            elif 17 <= position <= 24:
                totalPushes += frequency * 3
            else:
                totalPushes += frequency * 4
            position += 1

        return totalPushes