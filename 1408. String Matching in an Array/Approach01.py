class Solution:
    def stringMatching(self, words: list[str]) -> list[str]:
        substrings = []  # Stores words that are substrings of other words

        for smallerWord in words:
            for largerWord in words:
                # Check if the smaller word is a substring of the larger word
                if len(smallerWord) < len(largerWord) and largerWord.find(smallerWord) != -1:
                    substrings.append(smallerWord)
                    break  # No need to check further once found

        return substrings