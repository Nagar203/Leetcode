#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adjacencyList(n + 1);
        queue<pair<int, int>> bfsQueue{{{1, 0}}};

        // minTime[node][0] := the first minimum time to reach the node
        // minTime[node][1] := the second minimum time to reach the node
        vector<vector<int>> minTime(n + 1, vector<int>(2, INT_MAX));
        minTime[1][0] = 0;

        // Build the adjacency list for the graph
        for (const vector<int>& edge : edges) {
            const int u = edge[0];
            const int v = edge[1];
            adjacencyList[u].push_back(v);
            adjacencyList[v].push_back(u);
        }

        // Perform BFS to find the second minimum time to reach node n
        while (!bfsQueue.empty()) {
            const auto [currentNode, prevTime] = bfsQueue.front();
            bfsQueue.pop();

            // Calculate the wait time based on the traffic light signal
            const int numChangeSignal = prevTime / change;
            const int waitTime = (numChangeSignal % 2 == 0) ? 0 : change - prevTime % change;
            const int newTime = prevTime + waitTime + time;

            // Traverse the neighbors of the current node
            for (const int neighbor : adjacencyList[currentNode]) {
                // Update the minimum time to reach the neighbor
                if (newTime < minTime[neighbor][0]) {
                    minTime[neighbor][0] = newTime;
                    bfsQueue.emplace(neighbor, newTime);
                }
                // Update the second minimum time to reach the neighbor
                else if (minTime[neighbor][0] < newTime && newTime < minTime[neighbor][1]) {
                    if (neighbor == n)
                        return newTime;
                    minTime[neighbor][1] = newTime;
                    bfsQueue.emplace(neighbor, newTime);
                }
            }
        }

        throw;
    }
};
