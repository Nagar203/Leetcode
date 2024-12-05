class Solution:
    def canChange(self, start: str, target: str) -> bool:
        length = len(start)
        startIndex = 0  # Index for the start string
        targetIndex = 0  # Index for the target string

        while startIndex <= length and targetIndex <= length:
            while startIndex < length and start[startIndex] == '_':
                startIndex += 1
            while targetIndex < length and target[targetIndex] == '_':
                targetIndex += 1

            if startIndex == length or targetIndex == length:
                return startIndex == length and targetIndex == length

            if start[startIndex] != target[targetIndex]:
                return False

            if start[startIndex] == 'R' and startIndex > targetIndex:
                return False

            if start[startIndex] == 'L' and startIndex < targetIndex:
                return False

            startIndex += 1
            targetIndex += 1

        return True