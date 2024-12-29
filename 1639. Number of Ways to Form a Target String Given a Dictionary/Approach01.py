class Solution:
    MOD = int(1e9+7)
    
    def __init__(self):
        self.memo = []
        self.targetLength = 0
        self.wordLength = 0
    
    def solve(self, targetIndex, columnIndex, charFrequency, target):
        if targetIndex == self.targetLength:  # Completed target formation
            return 1
        if columnIndex == self.wordLength:  # Exhausted all columns
            return 0
        if self.memo[targetIndex][columnIndex] != -1:  # Return memoized result
            return self.memo[targetIndex][columnIndex]
        
        # Option 1: Skip current column
        skipColumn = self.solve(targetIndex, columnIndex + 1, charFrequency, target) % self.MOD
        
        # Option 2: Use current column
        useColumn = (charFrequency[ord(target[targetIndex]) - ord('a')][columnIndex] * 
                     self.solve(targetIndex + 1, columnIndex + 1, charFrequency, target)) % self.MOD
        
        self.memo[targetIndex][columnIndex] = (skipColumn + useColumn) % self.MOD
        return self.memo[targetIndex][columnIndex]
    
    def numWays(self, words, target):
        self.wordLength = len(words[0])
        self.targetLength = len(target)
        
        # Build frequency table for each character at every column
        charFrequency = [[0] * self.wordLength for _ in range(26)]
        for column in range(self.wordLength):
            for word in words:
                charFrequency[ord(word[column]) - ord('a')][column] += 1
        
        # Initialize memoization table
        self.memo = [[-1] * self.wordLength for _ in range(self.targetLength)]
        return self.solve(0, 0, charFrequency, target)