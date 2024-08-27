#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double maxProbability(int numNodes, vector<vector<int>>& edges, vector<double>& successProbabilities, int startNode, int endNode) {
        vector<vector<pair<int, double>>> graph(numNodes);
        priority_queue<pair<double, int>> maxHeap;
        maxHeap.emplace(1.0, startNode);
        vector<bool> visited(numNodes);

        for (int i = 0; i < edges.size(); ++i) {
            const int nodeA = edges[i][0];
            const int nodeB = edges[i][1];
            const double probability = successProbabilities[i];
            graph[nodeA].emplace_back(nodeB, probability);
            graph[nodeB].emplace_back(nodeA, probability);
        }

        while (!maxHeap.empty()) {
            const auto [currentProbability, currentNode] = maxHeap.top();
            maxHeap.pop();
            if (currentNode == endNode) {
                return currentProbability;
            }
            if (visited[currentNode]) {
                continue;
            }
            visited[currentNode] = true;
            for (const auto& [adjacentNode, edgeProbability] : graph[currentNode]) {
                if (visited[adjacentNode]) {
                    continue;
                }
                maxHeap.emplace(currentProbability * edgeProbability, adjacentNode);
            }
        }

        return 0;
    }
};