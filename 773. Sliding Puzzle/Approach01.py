from collections import deque

class Solution:
    def slidingPuzzle(self, board):
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        rows, cols = 2, 3
        targetState = "123450"
        initialState = ''.join(str(board[row][col]) for row in range(rows) for col in range(cols))

        if initialState == targetState:
            return 0

        stateQueue = deque([initialState])
        visitedStates = {initialState}

        steps = 0
        while stateQueue:
            steps += 1
            for _ in range(len(stateQueue)):
                currentState = stateQueue.popleft()
                zeroIndex = currentState.index('0')
                zeroRow, zeroCol = divmod(zeroIndex, cols)

                for dx, dy in directions:
                    newRow, newCol = zeroRow + dx, zeroCol + dy

                    if newRow < 0 or newRow >= rows or newCol < 0 or newCol >= cols:
                        continue

                    swapIndex = newRow * cols + newCol
                    nextState = list(currentState)
                    nextState[zeroIndex], nextState[swapIndex] = nextState[swapIndex], nextState[zeroIndex]
                    nextState = ''.join(nextState)

                    if nextState == targetState:
                        return steps

                    if nextState not in visitedStates:
                        stateQueue.append(nextState)
                        visitedStates.add(nextState)

        return -1