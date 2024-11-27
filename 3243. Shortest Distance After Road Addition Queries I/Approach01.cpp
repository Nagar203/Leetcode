#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> result;
        vector<int> distances(n);
        vector<vector<int>> adjacencyList(n);

        // Initialize the distances and graph (adjacency list)
        for (int i = 0; i < n; ++i) {
            distances[i] = i;
        }

        for (int i = 0; i < n - 1; ++i) {
            adjacencyList[i].push_back(i + 1);
        }

        // Process each query
        for (const auto& query : queries) {
            int startNode = query[0];
            int endNode = query[1];
            adjacencyList[startNode].push_back(endNode);

            // Update distance and perform BFS if necessary
            if (distances[startNode] + 1 < distances[endNode]) {
                distances[endNode] = distances[startNode] + 1;
                bfs(adjacencyList, endNode, distances);
            }
            result.push_back(distances[n - 1]);
        }

        return result;
    }

private:
    void bfs(const vector<vector<int>>& adjacencyList, int startNode, vector<int>& distances) {
        queue<int> q;
        q.push(startNode);

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();

            for (int neighbor : adjacencyList[currentNode]) {
                if (distances[currentNode] + 1 < distances[neighbor]) {
                    distances[neighbor] = distances[currentNode] + 1;
                    q.push(neighbor);
                }
            }
        }
    }
};