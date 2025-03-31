class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        splitCosts = []
        minScore = 0
        maxScore = 0

        for i in range(len(weights) - 1):
            splitCosts.append(weights[i] + weights[i + 1])

        splitCosts.sort()

        for i in range(k - 1):
            minScore += splitCosts[i]
            maxScore += splitCosts[-1 - i]

        return maxScore - minScore