from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        candidates.sort()
        self.dfs(candidates, 0, target, [], result)
        return result

    def dfs(self, A: List[int], s: int, target: int, path: List[int], result: List[List[int]]):
        if target < 0:
            return
        if target == 0:
            result.append(path[:])  # Append a copy of path
            return

        for i in range(s, len(A)):
            if i > s and A[i] == A[i - 1]:
                continue
            path.append(A[i])
            self.dfs(A, i + 1, target - A[i], path, result)
            path.pop()