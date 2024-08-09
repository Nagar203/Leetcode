class Solution:
    def numMagicSquaresInside(self, grid):
        magicSquareCount = 0

        # Traverse through the grid, considering each 3x3 section
        for row in range(len(grid) - 2):
            for col in range(len(grid[0]) - 2):
                if self.isMagicSquare(grid, row, col):
                    magicSquareCount += 1

        return magicSquareCount

    # Function to check if a 3x3 section starting at (row, col) is a magic square
    def isMagicSquare(self, grid, row, col):
        # Check that all values are between 1 and 9 and unique
        digits = [0] * 10
        for i in range(3):
            for j in range(3):
                value = grid[row + i][col + j]
                if value < 1 or value > 9 or digits[value] > 0:
                    return False
                digits[value] += 1

        # Check the sums of the rows, columns, and diagonals
        sum1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2]
        sum2 = grid[row + 1][col] + grid[row + 1][col + 1] + grid[row + 1][col + 2]
        sum3 = grid[row + 2][col] + grid[row + 2][col + 1] + grid[row + 2][col + 2]

        sum4 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col]
        sum5 = grid[row][col + 1] + grid[row + 1][col + 1] + grid[row + 2][col + 1]
        sum6 = grid[row][col + 2] + grid[row + 1][col + 2] + grid[row + 2][col + 2]

        diagonal1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2]
        diagonal2 = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col]

        # Return true if all sums are equal
        return (sum1 == sum2 and sum2 == sum3 and
                sum3 == sum4 and sum4 == sum5 and
                sum5 == sum6 and sum6 == diagonal1 and
                diagonal1 == diagonal2)
