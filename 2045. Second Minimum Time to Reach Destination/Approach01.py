from collections import deque
import sys

class Solution:
    def secondMinimum(self, n: int, edges: List[List[int]], time: int, change: int) -> int:
        adjacencyList = [[] for _ in range(n + 1)]
        bfsQueue = deque([(1, 0)])

        # minTime[node][0] := the first minimum time to reach the node
        # minTime[node][1] := the second minimum time to reach the node
        minTime = [[sys.maxsize, sys.maxsize] for _ in range(n + 1)]
        minTime[1][0] = 0

        # Build the adjacency list for the graph
        for edge in edges:
            u = edge[0]
            v = edge[1]
            adjacencyList[u].append(v)
            adjacencyList[v].append(u)

        # Perform BFS to find the second minimum time to reach node n
        while bfsQueue:
            currentNode, prevTime = bfsQueue.popleft()

            # Calculate the wait time based on the traffic light signal
            numChangeSignal = prevTime // change
            waitTime = 0 if numChangeSignal % 2 == 0 else change - prevTime % change
            newTime = prevTime + waitTime + time

            # Traverse the neighbors of the current node
            for neighbor in adjacencyList[currentNode]:
                # Update the minimum time to reach the neighbor
                if newTime < minTime[neighbor][0]:
                    minTime[neighbor][0] = newTime
                    bfsQueue.append((neighbor, newTime))
                # Update the second minimum time to reach the neighbor
                elif minTime[neighbor][0] < newTime < minTime[neighbor][1]:
                    if neighbor == n:
                        return newTime
                    minTime[neighbor][1] = newTime
                    bfsQueue.append((neighbor, newTime))
