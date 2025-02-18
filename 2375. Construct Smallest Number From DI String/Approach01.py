class Solution:
    def smallestNumber(self, pattern: str) -> str:
        result = ""
        numStack = ["1"]

        for direction in pattern:
            maxSoFar = numStack[-1]

            if direction == 'I':
                # Pop all elements from the stack and add them to result
                while numStack:
                    maxSoFar = max(maxSoFar, numStack[-1])
                    result += numStack.pop()

            numStack.append(chr(ord(maxSoFar) + 1))

        # Pop remaining elements in the stack
        while numStack:
            result += numStack.pop()

        return result