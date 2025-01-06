class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        result = [0] * n
        count = 0
        operations = 0

        # Traverse from left to right
        for i in range(n):
            result[i] += operations
            count += int(boxes[i])  # Count the number of '1's encountered so far
            operations += count    # Update the number of operations

        count = 0
        operations = 0

        # Traverse from right to left
        for i in range(n - 1, -1, -1):
            result[i] += operations
            count += int(boxes[i])  # Count the number of '1's encountered so far
            operations += count    # Update the number of operations

        return result