from typing import *

class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        # dp[i] represents the minimum height needed to place the first i books
        dp = [float('inf')] * (len(books) + 1)
        dp[0] = 0

        for i in range(len(books)):
            currentShelfWidth = 0
            currentShelfHeight = 0
            # Try placing books from index j to i on the current shelf.
            for j in range(i, -1, -1):
                bookWidth = books[j][0]
                bookHeight = books[j][1]
                currentShelfWidth += bookWidth
                if currentShelfWidth > shelfWidth:
                    break  # Shelf width exceeded, cannot place more books on this shelf.
                currentShelfHeight = max(currentShelfHeight, bookHeight)
                dp[i + 1] = min(dp[i + 1], dp[j] + currentShelfHeight)

        return dp[-1]
