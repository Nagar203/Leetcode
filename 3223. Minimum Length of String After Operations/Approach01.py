class Solution:
    def minimumLength(self, s: str) -> int:
        charFrequency = {}
        length = len(s)

        # Count the frequency of each character in the string
        for ch in s:
            charFrequency[ch] = charFrequency.get(ch, 0) + 1

        # Adjust the length based on character frequencies
        for character, frequency in charFrequency.items():
            if frequency % 2 == 0 and frequency > 2:
                length = length - frequency + 2
            elif frequency % 2 != 0 and frequency > 2:
                length = length - frequency + 1

        return length