class Solution:
    def maxDifference(self, s: str) -> int:
        charFrequency = [0] * 26
        maxOddFrequency = 0
        minEvenFrequency = len(s)

        for ch in s:
            charFrequency[ord(ch) - ord('a')] += 1
        
        for frequency in charFrequency:
            if frequency == 0:
                continue
            if frequency % 2 == 0:
                minEvenFrequency = min(minEvenFrequency, frequency)
            else:
                maxOddFrequency = max(maxOddFrequency, frequency)
        
        return maxOddFrequency - minEvenFrequency