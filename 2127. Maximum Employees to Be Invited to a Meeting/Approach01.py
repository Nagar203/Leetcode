from enum import Enum
import collections

class State(Enum):
    kInit = 0
    kVisiting = 1
    kVisited = 2

class Solution:
    def maximumInvitations(self, favorite: list[int]) -> int:
        numPeople = len(favorite)
        totalComponentLength = 0  # Length of all 2-cycle components.
        adjacencyList = [[] for _ in range(numPeople)]
        inDegrees = [0] * numPeople
        longestChainLength = [1] * numPeople

        # Build the graph using the favorite list.
        for person, likedPerson in enumerate(favorite):
            adjacencyList[person].append(likedPerson)
            inDegrees[likedPerson] += 1

        # Perform topological sorting to calculate maximum chain lengths.
        queue = collections.deque([person for person, inDegree in enumerate(inDegrees) if inDegree == 0])

        while queue:
            currentPerson = queue.popleft()
            for neighbor in adjacencyList[currentPerson]:
                inDegrees[neighbor] -= 1
                if inDegrees[neighbor] == 0:
                    queue.append(neighbor)
                longestChainLength[neighbor] = max(longestChainLength[neighbor], 1 + longestChainLength[currentPerson])

        # Calculate the total length of all 2-cycle components.
        for person in range(numPeople):
            if favorite[favorite[person]] == person:
                # Found a 2-cycle: person <-> favorite[person].
                totalComponentLength += longestChainLength[person] + longestChainLength[favorite[person]]

        maxCycleLength = 0  # Longest cycle in the graph.
        parent = [-1] * numPeople
        visitedNodes = set()
        nodeStates = [State.kInit] * numPeople

        # Helper function to find the length of a cycle.
        def findCycle(node: int) -> None:
            nonlocal maxCycleLength
            visitedNodes.add(node)
            nodeStates[node] = State.kVisiting
            for neighbor in adjacencyList[node]:
                if neighbor not in visitedNodes:
                    parent[neighbor] = node
                    findCycle(neighbor)
                elif nodeStates[neighbor] == State.kVisiting:
                    # Found a cycle, calculate its length.
                    currentNode = node
                    cycleLength = 1
                    while currentNode != neighbor:
                        currentNode = parent[currentNode]
                        cycleLength += 1
                    maxCycleLength = max(maxCycleLength, cycleLength)
            nodeStates[node] = State.kVisited

        # Start DFS from every unvisited node to detect cycles.
        for person in range(numPeople):
            if person not in visitedNodes:
                findCycle(person)

        return max(totalComponentLength // 2, maxCycleLength)