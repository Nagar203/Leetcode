from typing import List

class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        numQuestions = len(questions)
        maxPoints = [0] * (numQuestions + 1)

        for currentIndex in range(numQuestions - 1, -1, -1):
            currentPoints = questions[currentIndex][0]
            brainpower = questions[currentIndex][1]
            nextQuestionIndex = currentIndex + brainpower + 1
            nextQuestionPoints = maxPoints[nextQuestionIndex] if nextQuestionIndex < numQuestions else 0
            maxPoints[currentIndex] = max(currentPoints + nextQuestionPoints, maxPoints[currentIndex + 1])
        
        return maxPoints[0]