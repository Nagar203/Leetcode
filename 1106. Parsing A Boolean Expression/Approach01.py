import functools
import operator

class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        def dfs(startIndex: int, endIndex: int) -> bool:
            if startIndex == endIndex:
                return True if expression[startIndex] == 't' else False

            subExpressions = []
            currentLayer = 0

            for i in range(startIndex, endIndex + 1):
                currentChar = expression[i]
                if currentLayer == 0 and currentChar in '!&|':
                    operatorChar = currentChar
                elif currentChar == '(':
                    currentLayer += 1
                    if currentLayer == 1:
                        leftStart = i + 1
                elif currentChar == ')':
                    currentLayer -= 1
                    if currentLayer == 0:
                        subExpressions.append(dfs(leftStart, i - 1))
                elif currentChar == ',' and currentLayer == 1:
                    subExpressions.append(dfs(leftStart, i - 1))
                    leftStart = i + 1

            if operatorChar == '|':
                return functools.reduce(operator.or_, subExpressions)
            if operatorChar == '&':
                return functools.reduce(operator.and_, subExpressions)
            if operatorChar == '!':
                return not subExpressions[0]

        return dfs(0, len(expression) - 1)
