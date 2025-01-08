class Solution:
    # Helper function to check if str1 is both a prefix and suffix of str2
    def isPrefixAndSuffix(self, prefixSuffixCandidate, targetString):
        candidateLength = len(prefixSuffixCandidate)
        targetLength = len(targetString)

        # Extract the prefix and suffix from the target string
        prefix = targetString[:candidateLength]
        suffix = targetString[targetLength - candidateLength:]

        # Check if both the prefix and suffix match the candidate string
        if prefix == prefixSuffixCandidate and suffix == prefixSuffixCandidate:
            return 1
        return 0

    # Count all valid prefix-suffix pairs
    def countPrefixSuffixPairs(self, words):
        totalWords = len(words)
        validPairCount = 0

        # Iterate over all pairs of strings
        for i in range(totalWords - 1):
            for j in range(i + 1, totalWords):
                # Check if the first word can be a prefix and suffix of the second word
                if len(words[i]) <= len(words[j]):
                    validPairCount += self.isPrefixAndSuffix(words[i], words[j])

        return validPairCount