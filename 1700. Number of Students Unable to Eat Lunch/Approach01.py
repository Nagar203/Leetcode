from typing import *

class Solution:
    def countStudents(self, student: List[int], sand: List[int]) -> int:
        n = len(student)
        arr = [0, 0]

        for x in student:
            arr[x] += 1

        for i in range(n):
            if arr[sand[i]] == 0:
                return n - i
            arr[sand[i]] -= 1

        return 0
