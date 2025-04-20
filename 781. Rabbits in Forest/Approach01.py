from typing import List

class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        totalRabbits = 0
        answerFrequency = [0] * 1000

        for reportedSameColorCount in answers:
            if answerFrequency[reportedSameColorCount] % (reportedSameColorCount + 1) == 0:
                totalRabbits += reportedSameColorCount + 1
            answerFrequency[reportedSameColorCount] += 1

        return totalRabbits