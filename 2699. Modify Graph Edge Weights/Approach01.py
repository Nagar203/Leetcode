from typing import *

import heapq
from typing import List, Tuple

class Solution:
    def modifiedGraphEdges(self, numNodes: int, edges: List[List[int]], source: int, destination: int, target: int) -> List[List[int]]:
        maxWeight = 2_000_000_000
        adjacencyList = [[] for _ in range(numNodes)]

        # Build the adjacency list
        for edge in edges:
            startNode, endNode, weight = edge
            if weight != -1:  # Only add positive-weight edges to adjacency list
                adjacencyList[startNode].append((endNode, weight))
                adjacencyList[endNode].append((startNode, weight))

        # Calculate the shortest path from source to destination
        distanceToDestination = self.findShortestPath(adjacencyList, source, destination)
        if distanceToDestination < target:
            return []
        if distanceToDestination == target:
            # Change the weights of negative edges to an impossible value.
            for edge in edges:
                if edge[2] == -1:
                    edge[2] = maxWeight
            return edges

        # Adjust negative edges' weights to achieve the desired shortest path
        for i in range(len(edges)):
            startNode, endNode = edges[i][0], edges[i][1]
            weight = edges[i][2]
            if weight != -1:
                continue
            # Set weight to 1 temporarily to try achieving the target distance
            edges[i][2] = 1
            adjacencyList[startNode].append((endNode, 1))
            adjacencyList[endNode].append((startNode, 1))
            distanceToDestination = self.findShortestPath(adjacencyList, source, destination)

            if distanceToDestination <= target:
                edges[i][2] += (target - distanceToDestination)  # Adjust weight to make the total distance equal to the target
                # Change the weights of remaining negative edges to an impossible value.
                for j in range(i + 1, len(edges)):
                    if edges[j][2] == -1:
                        edges[j][2] = maxWeight
                return edges

        return []

    def findShortestPath(self, adjacencyList: List[List[Tuple[int, int]]], source: int, destination: int) -> int:
        # Initialize the minimum distances array with infinity
        minDistances = [float('inf')] * len(adjacencyList)
        minHeap = []  # Priority queue to store (distance, node) pairs

        # Set the distance to the source as 0 and push to the priority queue
        minDistances[source] = 0
        heapq.heappush(minHeap, (0, source))

        while minHeap:
            currentDistance, currentNode = heapq.heappop(minHeap)
            # Skip processing if a shorter path to currentNode is already found
            if currentDistance > minDistances[currentNode]:
                continue
            # Traverse all adjacent nodes
            for adjacentNode, edgeWeight in adjacencyList[currentNode]:
                # If a shorter path is found
                if currentDistance + edgeWeight < minDistances[adjacentNode]:
                    minDistances[adjacentNode] = currentDistance + edgeWeight
                    heapq.heappush(minHeap, (minDistances[adjacentNode], adjacentNode))

        return minDistances[destination]