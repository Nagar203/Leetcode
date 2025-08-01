class Solution:
    def generate(self, numRows):
        pascalTriangle = []

        # Initialize each row with 1s
        for rowIndex in range(numRows):
            pascalTriangle.append([1] * (rowIndex + 1))

        # Fill in the interior values
        for rowIndex in range(2, numRows):
            for colIndex in range(1, len(pascalTriangle[rowIndex]) - 1):
                pascalTriangle[rowIndex][colIndex] = (
                    pascalTriangle[rowIndex - 1][colIndex - 1] + pascalTriangle[rowIndex - 1][colIndex]
                )

        return pascalTriangle