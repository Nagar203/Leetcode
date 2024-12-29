class Solution:
    MOD = int(1e9+7)
    
    def numWays(self, words, target):
        wordLength = len(words[0])
        targetLength = len(target)
        
        # Build frequency table for each character at every column
        charFrequency = [[0] * wordLength for _ in range(26)]
        for column in range(wordLength):
            for word in words:
                charFrequency[ord(word[column]) - ord('a')][column] += 1
        
        # dp[targetLength][columnLength]: Total ways to form target of length targetLength using columnLength columns
        dp = [[0] * (wordLength + 1) for _ in range(targetLength + 1)]
        dp[0][0] = 1  # Base case: 1 way to form empty target
        
        for targetIndex in range(targetLength + 1):
            for columnIndex in range(wordLength + 1):
                # Skip current column
                if columnIndex < wordLength:
                    dp[targetIndex][columnIndex + 1] = (dp[targetIndex][columnIndex + 1] + dp[targetIndex][columnIndex]) % self.MOD
                
                # Use current column
                if targetIndex < targetLength and columnIndex < wordLength:
                    dp[targetIndex + 1][columnIndex + 1] = (dp[targetIndex + 1][columnIndex + 1] + 
                        charFrequency[ord(target[targetIndex]) - ord('a')][columnIndex] * dp[targetIndex][columnIndex]) % self.MOD
        
        return dp[targetLength][wordLength]