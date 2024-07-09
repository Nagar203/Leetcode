from typing import List

class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        wait = 0
        curr = 0

        for c in customers:
            curr = max(curr, 1.0 * c[0]) + c[1]
            wait += curr - c[0]

        return wait / len(customers)