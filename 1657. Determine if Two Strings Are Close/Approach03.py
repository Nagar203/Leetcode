class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2):
            return False

        freq_1 = [0] * 26
        freq_2 = [0] * 26

        for s in word1:
            freq_1[ord(s) - ord('a')] += 1

        for s in word2:
            freq_2[ord(s) - ord('a')] += 1

        for i in range(26):
            if freq_1[i] == 0 and freq_2[i] != 0:
                return False
            if freq_2[i] == 0 and freq_1[i] != 0:
                return False

        freq_1.sort()
        freq_2.sort()

        for i in range(26):
            if freq_1[i] != freq_2[i]:
                return False

        return True
