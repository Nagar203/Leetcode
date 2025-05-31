from collections import deque

class Solution:
    def snakesAndLadders(self, board: list[list[int]]) -> int:
        n = len(board)
        flattenedBoard = [0] * (n * n)
        row, col, index, direction = n - 1, 0, 0, 1

        while index < n * n:
            flattenedBoard[index] = board[row][col]
            index += 1
            if direction == 1 and col == n - 1:
                direction = -1
                row -= 1
            elif direction == -1 and col == 0:
                direction = 1
                row -= 1
            else:
                col += direction

        visited = [False] * (n * n)
        bfsQueue = deque()
        startSquare = flattenedBoard[0] - 1 if flattenedBoard[0] > -1 else 0

        bfsQueue.append(startSquare)
        visited[startSquare] = True

        moves = 0

        while bfsQueue:
            for _ in range(len(bfsQueue)):
                current = bfsQueue.popleft()

                if current == n * n - 1:
                    return moves

                for nextSquare in range(current + 1, min(current + 6, n * n - 1) + 1):
                    destination = flattenedBoard[nextSquare] - 1 if flattenedBoard[nextSquare] > -1 else nextSquare
                    if not visited[destination]:
                        visited[destination] = True
                        bfsQueue.append(destination)

            moves += 1

        return -1