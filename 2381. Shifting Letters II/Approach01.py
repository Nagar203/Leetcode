class Solution:
    def shiftingLetters(self, s: str, shifts: list[list[int]]) -> str:
        accumulatedShift = 0  # Accumulated shift at each position
        shiftDifferences = [0] * (len(s) + 1)  # Timeline of shifts

        # Apply shifts to the timeline
        for shift in shifts:
            startIdx = shift[0]  # Starting index for the shift
            endIdx = shift[1]    # Ending index for the shift
            direction = shift[2]  # Direction of the shift (1 for right, 0 for left)
            shiftValue = 1 if direction else -1  # +1 for right shift, -1 for left shift
            shiftDifferences[startIdx] += shiftValue
            shiftDifferences[endIdx + 1] -= shiftValue

        # Apply the accumulated shifts to the string
        s = list(s)  # Convert string to list for mutable operations
        for i in range(len(s)):
            accumulatedShift = (accumulatedShift + shiftDifferences[i]) % 26
            newCharPos = (ord(s[i]) - ord('a') + accumulatedShift + 26) % 26
            s[i] = chr(ord('a') + newCharPos)

        return ''.join(s)