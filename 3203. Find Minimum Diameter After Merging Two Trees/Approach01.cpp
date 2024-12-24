class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& treeEdges1, vector<vector<int>>& treeEdges2) {
        const int diameterTree1 = getDiameter(treeEdges1);
        const int diameterTree2 = getDiameter(treeEdges2);
        const int combinedDiameter = (diameterTree1 + 1) / 2 + (diameterTree2 + 1) / 2 + 1;
        return max({diameterTree1, diameterTree2, combinedDiameter});
    }

private:
    int getDiameter(const vector<vector<int>>& treeEdges) {
        const int totalNodes = treeEdges.size() + 1;
        vector<vector<int>> adjacencyList(totalNodes);

        for (const vector<int>& edge : treeEdges) {
            const int node1 = edge[0];
            const int node2 = edge[1];
            adjacencyList[node1].push_back(node2);
            adjacencyList[node2].push_back(node1);
        }

        int maxTreeDiameter = 0;
        calculateMaxDepth(adjacencyList, 0, -1, maxTreeDiameter);
        return maxTreeDiameter;
    }

    // Returns the maximum depth of the subtree rooted at currentNode.
    int calculateMaxDepth(const vector<vector<int>>& adjacencyList, int currentNode, int parentNode, int& maxTreeDiameter) {
        int maxSubtreeDepth1 = 0;
        int maxSubtreeDepth2 = 0;
        for (const int neighbor : adjacencyList[currentNode]) {
            if (neighbor == parentNode)
                continue;
            const int currentSubtreeDepth = calculateMaxDepth(adjacencyList, neighbor, currentNode, maxTreeDiameter);
            if (currentSubtreeDepth > maxSubtreeDepth1) {
                maxSubtreeDepth2 = maxSubtreeDepth1;
                maxSubtreeDepth1 = currentSubtreeDepth;
            } else if (currentSubtreeDepth > maxSubtreeDepth2) {
                maxSubtreeDepth2 = currentSubtreeDepth;
            }
        }
        maxTreeDiameter = max(maxTreeDiameter, maxSubtreeDepth1 + maxSubtreeDepth2);
        return 1 + maxSubtreeDepth1;
    }
};