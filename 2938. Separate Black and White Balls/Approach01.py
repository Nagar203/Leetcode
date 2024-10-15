class Solution:
    def minimumSteps(self, binaryString: str) -> int:
        totalSteps = 0
        countOnes = 0

        for currentChar in binaryString:
            if currentChar == '1':
                countOnes += 1
            else:  # Move 1s to the front of the current '0'.
                totalSteps += countOnes

        return totalSteps