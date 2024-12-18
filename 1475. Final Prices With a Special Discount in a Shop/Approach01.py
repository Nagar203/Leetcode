class Solution:
    def finalPrices(self, prices):
        totalItems = len(prices)
        for currentItem in range(totalItems - 1):
            for nextItem in range(currentItem + 1, totalItems):
                if nextItem > currentItem and prices[currentItem] >= prices[nextItem]:
                    prices[currentItem] -= prices[nextItem]
                    break
        return prices