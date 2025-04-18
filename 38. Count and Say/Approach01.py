class Solution:
    def countAndSay(self, n: int) -> str:
        currentSequence = "1"

        while n > 1:
            nextSequence = ""
            i = 0
            while i < len(currentSequence):
                count = 1
                while i + 1 < len(currentSequence) and currentSequence[i] == currentSequence[i + 1]:
                    count += 1
                    i += 1
                nextSequence += str(count) + currentSequence[i]
                i += 1
            currentSequence = nextSequence
            n -= 1

        return currentSequence
