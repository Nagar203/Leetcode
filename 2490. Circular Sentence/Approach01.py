from typing import *

class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        words = sentence.split(" ")
        firstLettersConcat = ''
        shiftedLastLetters = ''
        
        for word in words:
            firstLettersConcat += word[0]
            shiftedLastLetters += word[-1]
        
        sentenceLength = len(shiftedLastLetters)
        shiftedLastLetters = shiftedLastLetters[-1] + shiftedLastLetters[:sentenceLength - 1]
        
        return shiftedLastLetters == firstLettersConcat