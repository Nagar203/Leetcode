from typing import *

class Solution:
    def stoneGameII(self, piles):
        numberOfPiles = len(piles)
        memo = [[0] * numberOfPiles for _ in range(numberOfPiles)]
        
        # Compute the suffix sum for each index, which represents the sum of all elements from that index to the end.
        suffixSum = piles[:]  # suffixSum[i] := sum(piles[i..n))
        for i in range(numberOfPiles - 2, -1, -1):
            suffixSum[i] += suffixSum[i + 1]

        # Start the recursion to find the maximum stones Alice can collect
        return self.getMaxStones(suffixSum, 0, 1, memo)

    def getMaxStones(self, suffixSum, currentIndex, maxM, memo):
        # If the current player can take all remaining piles, return the sum of those piles
        if currentIndex + 2 * maxM >= len(memo):
            return suffixSum[currentIndex]

        # If this state has already been computed, return the stored result to avoid recomputation
        if memo[currentIndex][maxM] > 0:
            return memo[currentIndex][maxM]

        # Calculate the minimum number of stones the opponent can leave to Alice
        minimumOpponentStones = suffixSum[currentIndex]

        # Iterate over all possible choices for X, where X ranges from 1 to 2 * M
        # and determine the best worst-case scenario
        for X in range(1, 2 * maxM + 1):
            minimumOpponentStones = min(minimumOpponentStones, self.getMaxStones(suffixSum, currentIndex + X, max(maxM, X), memo))

        # Store the result in memo and return the maximum stones Alice can collect from this point
        memo[currentIndex][maxM] = suffixSum[currentIndex] - minimumOpponentStones
        return memo[currentIndex][maxM]