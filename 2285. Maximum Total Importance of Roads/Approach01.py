class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        result = 0
        count = [0] * n  # Initialize count array with zeros for each city

        for road in roads:
            u, v = road  # Unpack road into city indices
            count[u] += 1  # Increment count for city u
            count[v] += 1  # Increment count for city v

        count.sort()  # Sort the count array in ascending order

        for i in range(n):
            result += (i + 1) * count[i]  # Calculate importance contribution

        return result