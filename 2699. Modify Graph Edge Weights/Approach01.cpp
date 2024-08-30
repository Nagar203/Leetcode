#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int numNodes, vector<vector<int>>& edges, int source, int destination, int target) {
        constexpr int maxWeight = 2'000'000'000;
        vector<vector<pair<int, int>>> adjacencyList(numNodes);

        for (const vector<int>& edge : edges) {
            const int startNode = edge[0];
            const int endNode = edge[1];
            const int weight = edge[2];
            if (weight == -1)
                continue;
            adjacencyList[startNode].emplace_back(endNode, weight);
            adjacencyList[endNode].emplace_back(startNode, weight);
        }

        int distanceToDestination = findShortestPath(adjacencyList, source, destination);
        if (distanceToDestination < target)
            return {};
        if (distanceToDestination == target) {
            // Change the weights of negative edges to an impossible value.
            for (vector<int>& edge : edges)
                if (edge[2] == -1)
                    edge[2] = maxWeight;
            return edges;
        }

        for (int i = 0; i < edges.size(); ++i) {
            const int startNode = edges[i][0];
            const int endNode = edges[i][1];
            int& weight = edges[i][2];
            if (weight != -1)
                continue;
            weight = 1;
            adjacencyList[startNode].emplace_back(endNode, 1);
            adjacencyList[endNode].emplace_back(startNode, 1);
            distanceToDestination = findShortestPath(adjacencyList, source, destination);
            if (distanceToDestination <= target) {
                weight += target - distanceToDestination;
                // Change the weights of remaining negative edges to an impossible value.
                for (int j = i + 1; j < edges.size(); ++j)
                    if (edges[j][2] == -1)
                        edges[j][2] = maxWeight;
                return edges;
            }
        }

        return {};
    }

private:
    int findShortestPath(const vector<vector<pair<int, int>>>& adjacencyList, int source, int destination) {
        vector<int> minDistances(adjacencyList.size(), INT_MAX);
        using DistanceNodePair = pair<int, int>;  // (distance, node)
        priority_queue<DistanceNodePair, vector<DistanceNodePair>, greater<>> minHeap;

        minDistances[source] = 0;
        minHeap.emplace(minDistances[source], source);

        while (!minHeap.empty()) {
            const auto [currentDistance, currentNode] = minHeap.top();
            minHeap.pop();
            if (currentDistance > minDistances[currentNode])
                continue;
            for (const auto& [adjacentNode, edgeWeight] : adjacencyList[currentNode]) {
                if (currentDistance + edgeWeight < minDistances[adjacentNode]) {
                    minDistances[adjacentNode] = currentDistance + edgeWeight;
                    minHeap.emplace(minDistances[adjacentNode], adjacentNode);
                }
            }
        }

        return minDistances[destination];
    }
};