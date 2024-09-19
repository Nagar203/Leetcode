from typing import *

class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        return self.computeWays(expression, {})

    def computeWays(self, expression: str, memoization: dict):
        if expression in memoization:
            return memoization[expression]

        results = []

        for index in range(len(expression)):
            if expression[index] in "+-*":
                leftResults = self.computeWays(expression[:index], memoization)
                rightResults = self.computeWays(expression[index + 1:], memoization)

                for leftPart in leftResults:
                    for rightPart in rightResults:
                        if expression[index] == '+':
                            results.append(leftPart + rightPart)
                        elif expression[index] == '-':
                            results.append(leftPart - rightPart)
                        else:
                            results.append(leftPart * rightPart)

        if not results:
            results.append(int(expression))

        memoization[expression] = results
        return results