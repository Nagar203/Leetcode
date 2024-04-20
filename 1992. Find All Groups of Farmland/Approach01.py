class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        result = []

        def dfs(i, j, x, y):
            if i < 0 or i == len(land) or j < 0 or j == len(land[0]):
                return
            if land[i][j] != 1:
                return
            land[i][j] = 2
            x[0] = max(x[0], i)
            y[0] = max(y[0], j)
            dfs(i + 1, j, x, y)
            dfs(i, j + 1, x, y)

        for i in range(len(land)):
            for j in range(len(land[0])):
                if land[i][j] == 1:
                    x, y = [i], [j]
                    dfs(i, j, x, y)
                    result.append([i, j, x[0], y[0]])

        return result
