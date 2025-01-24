from enum import Enum

class NodeState(Enum):
    UNVISITED = 0
    VISITING = 1
    VISITED = 2

class Solution:
    def eventualSafeNodes(self, graph):
        safeNodes = []  # Stores the eventual safe nodes
        nodeStates = [NodeState.UNVISITED] * len(graph)  # Track the state of each node

        for currentNode in range(len(graph)):
            if not self.hasCycle(graph, currentNode, nodeStates):
                safeNodes.append(currentNode)

        return safeNodes

    def hasCycle(self, graph, currentNode, nodeStates):
        if nodeStates[currentNode] == NodeState.VISITING:  # Cycle detected
            return True
        if nodeStates[currentNode] == NodeState.VISITED:  # Already processed node
            return False

        nodeStates[currentNode] = NodeState.VISITING  # Mark as visiting
        for neighbor in graph[currentNode]:           # Explore all neighbors
            if self.hasCycle(graph, neighbor, nodeStates):
                return True

        nodeStates[currentNode] = NodeState.VISITED  # Mark as fully visited
        return False