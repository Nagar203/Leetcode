from typing import *

class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        result = 0
        i, j = 0, len(people) - 1

        while i <= j:
            result += 1
            remain = limit - people[j]
            if people[i] <= remain:
                i += 1
            j -= 1

        return result
