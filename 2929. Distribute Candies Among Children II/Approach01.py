class Solution:
    def distributeCandies(self, totalCandies: int, maxCandiesPerChild: int) -> int:
        limitPlusOne = maxCandiesPerChild + 1
        oneChildOverLimit = self.countWays(totalCandies - limitPlusOne)
        twoChildrenOverLimit = self.countWays(totalCandies - 2 * limitPlusOne)
        threeChildrenOverLimit = self.countWays(totalCandies - 3 * limitPlusOne)
        return (self.countWays(totalCandies) - 3 * oneChildOverLimit + 3 * twoChildrenOverLimit - threeChildrenOverLimit)
    def countWays(self, candies: int) -> int:
        if candies < 0:
            return 0
        return self.computeCombination(candies + 2, 2)  
    def computeCombination(self, n: int, k: int) -> int:
        result = 1
        for i in range(1, k + 1):
            result = result * (n - i + 1) // i
        return result