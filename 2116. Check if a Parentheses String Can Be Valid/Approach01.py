class Solution:
    def canBeValid(self, brackets: str, locked: str) -> bool:
        # If the length of the string is odd, it's impossible to make valid parentheses
        if len(brackets) % 2 == 1:
            return False

        # Check both directions: left-to-right and right-to-left
        leftToRightIsValid = self._validateBrackets(brackets, locked, isForward=True)
        brackets = brackets[::-1]
        locked = locked[::-1]
        rightToLeftIsValid = self._validateBrackets(brackets, locked, isForward=False)

        return leftToRightIsValid and rightToLeftIsValid

    def _validateBrackets(self, brackets: str, locked: str, isForward: bool) -> bool:
        changeableCount = 0  # Count of brackets that can be changed
        openCount = 0        # Count of open brackets
        closeCount = 0       # Count of close brackets

        for currentBracket, isLocked in zip(brackets, locked):
            if isLocked == '0':
                changeableCount += 1  # Bracket can be changed
            elif currentBracket == '(':
                openCount += 1  # Count open brackets
            else:  # currentBracket == ')'
                closeCount += 1  # Count close brackets

            # Check if it's valid based on the current counts
            if isForward and changeableCount + openCount - closeCount < 0:
                return False
            if not isForward and changeableCount + closeCount - openCount < 0:
                return False

        return True
