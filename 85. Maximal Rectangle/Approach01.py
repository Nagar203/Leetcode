from typing import *

class Solution:
    def NSR(self, heights):
        stack = []
        n = len(heights)
        pseudo_index = n
        right = [pseudo_index] * n
        for i in range(n - 1, -1, -1):
            while stack and heights[stack[-1]] >= heights[i]:
                stack.pop()
            if not stack:
                right[i] = pseudo_index
            else:
                right[i] = stack[-1]
            stack.append(i)
        return right

    def NSL(self, heights):
        stack = []
        n = len(heights)
        pseudo_index = -1
        left = [pseudo_index] * n
        for i in range(n):
            while stack and heights[stack[-1]] >= heights[i]:
                stack.pop()
            if not stack:
                left[i] = pseudo_index
            else:
                left[i] = stack[-1]
            stack.append(i)
        return left

    def MAH(self, heights):
        n = len(heights)
        right = self.NSR(heights)
        left = self.NSL(heights)
        width = [0] * n
        for i in range(n):
            width[i] = right[i] - left[i] - 1
        max_area = 0
        for i in range(n):
            area = width[i] * heights[i]
            max_area = max(max_area, area)
        return max_area

    def maximalRectangle(self, matrix):
        if not matrix:
            return 0
        n = len(matrix)
        m = len(matrix[0])
        height = [0] * m

        for i in range(m):
            height[i] = 1 if matrix[0][i] == '1' else 0

        max_area = self.MAH(height)

        for row in range(1, n):
            for col in range(m):
                if matrix[row][col] == '0':
                    height[col] = 0
                else:
                    height[col] += 1
            max_area = max(max_area, self.MAH(height))

        return max_area