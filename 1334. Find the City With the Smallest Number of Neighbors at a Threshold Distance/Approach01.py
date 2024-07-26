from typing import List

class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        resultCity = -1
        minReachableCities = n
        distanceMatrix = self.floydWarshall(n, edges, distanceThreshold)

        # Iterate through each city to find the number of reachable cities within the distance threshold
        for currentCity in range(n):
            reachableCitiesCount = 0
            for targetCity in range(n):
                if distanceMatrix[currentCity][targetCity] <= distanceThreshold:
                    reachableCitiesCount += 1
            # Update the result city if the current city has fewer or equal reachable cities
            if reachableCitiesCount <= minReachableCities:
                resultCity = currentCity
                minReachableCities = reachableCitiesCount

        return resultCity

    def floydWarshall(self, n: int, edges: List[List[int]], distanceThreshold: int) -> List[List[int]]:
        distanceMatrix = [[distanceThreshold + 1] * n for _ in range(n)]

        # Initialize the distance of each city to itself as 0
        for i in range(n):
            distanceMatrix[i][i] = 0

        # Set the initial distances based on the given edges
        for edge in edges:
            fromCity, toCity, weight = edge
            distanceMatrix[fromCity][toCity] = weight
            distanceMatrix[toCity][fromCity] = weight

        # Apply Floyd-Warshall algorithm to compute the shortest paths between all pairs of cities
        for intermediate in range(n):
            for start in range(n):
                for end in range(n):
                    distanceMatrix[start][end] = min(distanceMatrix[start][end], distanceMatrix[start][intermediate] + distanceMatrix[intermediate][end])

        return distanceMatrix
