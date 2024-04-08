from typing import *

from collections import deque

class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        n = len(students)
        que = deque(students)
        st = []

        for i in range(n):
            st.append(sandwiches[n - i - 1])

        last_served = 0
        while que and last_served < len(que):
            if st[-1] == que[0]:
                st.pop()
                que.popleft()
                last_served = 0
            else:
                que.append(que.popleft())
                last_served += 1

        return len(que)
