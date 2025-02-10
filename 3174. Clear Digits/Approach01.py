class Solution:
    def clearDigits(self, inputStr: str) -> str:
        resultStack = []
        
        for currentChar in inputStr:
            if resultStack and resultStack[-1].isalpha() and currentChar.isdigit():
                resultStack.pop()
            elif resultStack and resultStack[-1].isdigit() and currentChar.isalpha():
                resultStack.pop()
            else:
                resultStack.append(currentChar)
        
        return ''.join(resultStack)
