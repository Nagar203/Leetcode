from typing import *

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for token in tokens:
            if token.isdigit() or (token[0] == '-' and token[1:].isdigit()):
                stack.append(int(token))
            else:
                num2 = stack.pop()
                num1 = stack.pop()

                if token == '+':
                    result = num1 + num2
                elif token == '-':
                    result = num1 - num2
                elif token == '*':
                    result = num1 * num2
                elif token == '/':
                    result = int(num1 / num2)
                stack.append(result)
        return stack[0]
