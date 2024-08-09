class Solution:
    def numMagicSquaresInside(self, grid):
        magicSquareCount = 0

        # Traverse through the grid, considering each 3x3 section
        for row in range(len(grid) - 2):
            for col in range(len(grid[0]) - 2):
                # Check for basic properties: the center of the magic square must be 5
                if grid[row][col] % 2 == 0 and grid[row + 1][col + 1] == 5:
                    magicSquareCount += self.isMagicSquare(grid, row, col)

        return magicSquareCount

    # Function to check if a 3x3 section starting at (row, col) is a magic square
    def isMagicSquare(self, grid, row, col):
        squarePattern = ""

        # Construct a string pattern based on the elements' positions in the grid
        for position in [0, 1, 2, 5, 8, 7, 6, 3]:
            squarePattern += str(grid[row + position // 3][col + position % 3])

        # Check if the pattern matches any of the two valid magic square patterns
        return "4381672943816729".find(squarePattern) != -1 or \
               "9276183492761834".find(squarePattern) != -1
