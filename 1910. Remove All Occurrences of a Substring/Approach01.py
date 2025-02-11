class Solution:
    def removeOccurrences(self, inputStr: str, targetStr: str) -> str:
        while True:
            if targetStr in inputStr:
                index = inputStr.index(targetStr)
                inputStr = inputStr[:index] + inputStr[index + len(targetStr):]
            else:
                break
        return inputStr