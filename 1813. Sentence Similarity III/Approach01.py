from typing import *

class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        if len(sentence1) == len(sentence2):
            return sentence1 == sentence2

        words1 = self.split(sentence1)
        words2 = self.split(sentence2)
        size1 = len(words1)
        size2 = len(words2)

        if size1 > size2:
            return self.areSentencesSimilar(sentence2, sentence1)

        index = 0  # words1's index
        while index < size1 and words1[index] == words2[index]:
            index += 1
        while index < size1 and words1[index] == words2[index + size2 - size1]:
            index += 1

        return index == size1

    def split(self, sentence: str) -> list:
        return sentence.split()