#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int numNodes, vector<vector<int>>& edges) {
        vector<vector<int>> ancestors(numNodes); // Stores the ancestors for each node
        vector<vector<int>> graph(numNodes);     // Adjacency list for the graph

        // Build the graph from edges
        for (const vector<int>& edge : edges) {
            const int fromNode = edge[0];
            const int toNode = edge[1];
            graph[fromNode].push_back(toNode);
        }

        // Perform DFS for each node to find all ancestors
        for (int currentNode = 0; currentNode < numNodes; ++currentNode) {
            vector<bool> visited(numNodes, false);
            dfs(graph, currentNode, currentNode, visited, ancestors);
        }

        return ancestors;
    }

private:
    void dfs(const vector<vector<int>>& graph, int currentNode, int ancestor, vector<bool>& visited, vector<vector<int>>& ancestors) {
        visited[currentNode] = true;
        for (const int neighbor : graph[currentNode]) {
            if (visited[neighbor])
                continue;
            ancestors[neighbor].push_back(ancestor);
            dfs(graph, neighbor, ancestor, visited, ancestors);
        }
    }
};
