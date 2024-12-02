class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        searchWordLength = len(searchWord)
        print(searchWordLength)
        
        words = sentence.split(" ")
        print(words)
        
        for wordIndex, word in enumerate(words):
            if len(word) >= searchWordLength:
                if word[:searchWordLength] == searchWord:                    
                    print(word)
                    return wordIndex + 1
        return -1