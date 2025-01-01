class Solution:
    def maxScore(self, binaryString: str) -> int:
        stringLength = len(binaryString)
        totalOnesInString = binaryString.count('1')  # Total number of '1's in the string
        
        leftZeroCount = 0
        rightOneCount = totalOnesInString
        maximumScore = 0
        
        # Iterate up to the second last character to ensure both parts are non-empty
        for index in range(stringLength - 1):
            if binaryString[index] == '0':
                leftZeroCount += 1
            else:
                rightOneCount -= 1

            # Calculate the score and update the maximum score
            maximumScore = max(maximumScore, leftZeroCount + rightOneCount)
        
        return maximumScore