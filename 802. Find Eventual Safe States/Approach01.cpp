enum class NodeState { unvisited, visiting, visited };

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safeNodes;                    // Stores the eventual safe nodes
        vector<NodeState> nodeStates(graph.size(), NodeState::unvisited);  // Track the state of each node

        for (int currentNode = 0; currentNode < graph.size(); ++currentNode)
            if (!hasCycle(graph, currentNode, nodeStates))
                safeNodes.push_back(currentNode);

        return safeNodes;
    }

private:
    // Function to detect if a cycle exists starting from the given node
    bool hasCycle(const vector<vector<int>>& graph, int currentNode, vector<NodeState>& nodeStates) {
        if (nodeStates[currentNode] == NodeState::visiting)  // Cycle detected
            return true;
        if (nodeStates[currentNode] == NodeState::visited)  // Already processed node
            return false;

        nodeStates[currentNode] = NodeState::visiting;  // Mark as visiting
        for (const int neighbor : graph[currentNode])   // Explore all neighbors
            if (hasCycle(graph, neighbor, nodeStates))
                return true;

        nodeStates[currentNode] = NodeState::visited;  // Mark as fully visited
        return false;
    }
};