class Solution:
    def solveSudoku(self, board):
        self.backtrack(board, 0)

    def backtrack(self, board, cellIndex):
        if cellIndex == 81:  # All cells filled
            return True

        rowIndex = cellIndex // 9
        colIndex = cellIndex % 9

        if board[rowIndex][colIndex] != '.':
            return self.backtrack(board, cellIndex + 1)

        for digit in map(str, range(1, 10)):
            if self.isValidPlacement(board, rowIndex, colIndex, digit):
                board[rowIndex][colIndex] = digit
                if self.backtrack(board, cellIndex + 1):
                    return True
                board[rowIndex][colIndex] = '.'  # Undo choice

        return False

    def isValidPlacement(self, board, rowIndex, colIndex, digit):
        for index in range(9):
            if (board[index][colIndex] == digit or
                board[rowIndex][index] == digit or
                board[3 * (rowIndex // 3) + index // 3][3 * (colIndex // 3) + index % 3] == digit):
                return False
        return True
