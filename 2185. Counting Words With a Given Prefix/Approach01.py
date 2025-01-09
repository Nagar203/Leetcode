class Solution:
    def prefixCount(self, words: list[str], prefix: str) -> int:
        wordCount = len(words)  # Number of words in the input
        prefixLength = len(prefix)  # Length of the prefix
        matchingCount = 0  # Counter for words starting with the prefix
        
        for word in words:
            if len(word) >= prefixLength:  # Ensure the word is at least as long as the prefix
                wordPrefix = word[:prefixLength]  # Extract the prefix from the word
                if wordPrefix == prefix:  # Check if the prefix matches
                    matchingCount += 1
        
        return matchingCount  # Return the total count of matching words