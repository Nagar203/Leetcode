class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        minDeletions = float('inf')
        charFrequency = [0] * 26

        for ch in word:
            charFrequency[ord(ch) - ord('a')] += 1

        for baseFreq in charFrequency:
            deletions = 0
            for freq in charFrequency:
                if freq < baseFreq:
                    deletions += freq
                else:
                    deletions += max(0, freq - (baseFreq + k))
            minDeletions = min(minDeletions, deletions)

        return minDeletions
