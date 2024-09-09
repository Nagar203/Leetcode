from typing import *

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def spiralMatrix(self, numRows: int, numCols: int, head: ListNode) -> list[list[int]]:
        # Directions for moving right, down, left, up
        directionOffsets = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        matrix = [[-1] * numCols for _ in range(numRows)]

        currentRow = 0     # Current row position
        currentCol = 0     # Current column position
        directionIndex = 0 # Current direction index

        node = head
        while node:
            matrix[currentRow][currentCol] = node.val
            
            # Check if we need to change direction
            if (currentRow + directionOffsets[directionIndex][0] < 0 or
                currentRow + directionOffsets[directionIndex][0] == numRows or
                currentCol + directionOffsets[directionIndex][1] < 0 or
                currentCol + directionOffsets[directionIndex][1] == numCols or
                matrix[currentRow + directionOffsets[directionIndex][0]][currentCol + directionOffsets[directionIndex][1]] != -1):
                directionIndex = (directionIndex + 1) % 4

            currentRow += directionOffsets[directionIndex][0]
            currentCol += directionOffsets[directionIndex][1]
            node = node.next

        return matrix