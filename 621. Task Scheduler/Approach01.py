from typing import List
import heapq

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        mp = [0] * 26
        for task in tasks:
            mp[ord(task) - ord("A")] += 1

        pq = []
        time = 0

        for count in mp:
            if count > 0:
                heapq.heappush(pq, -count)

        while pq:
            temp = []
            cycle_time = 0
            for _ in range(n + 1):
                if pq:
                    freq = heapq.heappop(pq)
                    freq += 1
                    if freq < 0:
                        temp.append(freq)
                    cycle_time += 1

            if temp:
                time += n + 1
            else:
                time += cycle_time

            for it in temp:
                heapq.heappush(pq, it)

        return time
