class Solution:
    def minCost(self, basket1: list[int], basket2: list[int]) -> int:
        from collections import Counter

        item_count = Counter()
        for item in basket1:
            item_count[item] += 1
        for item in basket2:
            item_count[item] -= 1

        to_swap = []
        for item, count in item_count.items():
            if count % 2 != 0:
                return -1
            to_swap.extend([item] * (abs(count) // 2))

        if not to_swap:
            return 0

        min_element = min(min(basket1), min(basket2))
        to_swap.sort()
        total_swaps = len(to_swap) // 2

        total_cost = 0
        for i in range(total_swaps):
            total_cost += min(2 * min_element, to_swap[i])
        return total_cost
