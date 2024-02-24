from typing import *
from collections import defaultdict, deque

class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        adj = defaultdict(list)
        
        for meeting in meetings:
            person1, person2, time = meeting
            adj[person1].append((person2, time))
            adj[person2].append((person1, time))
        
        que = deque([(0, 0), (firstPerson, 0)])
        early_secret_time = [float('inf')] * n
        early_secret_time[0] = 0
        early_secret_time[firstPerson] = 0
        
        while que:
            person, time = que.popleft()
            
            for next_person, t in adj[person]:
                if t >= time and early_secret_time[next_person] > t:
                    early_secret_time[next_person] = t
                    que.append((next_person, t))
        
        result = [i for i in range(n) if early_secret_time[i] != float('inf')]
        return result
