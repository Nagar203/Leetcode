#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        
        for (const vector<int>& road : roads) {
            const int u = road[0];
            const int v = road[1];
            const int weight = road[2];
            graph[u].emplace_back(v, weight);
            graph[v].emplace_back(u, weight);
        }
        return dijkstra(graph, 0, n - 1);
    }

private:
    int dijkstra(const vector<vector<pair<int, int>>>& graph, int source, int destination) {
        constexpr int kMod = 1'000'000'007;
        vector<long> numberOfWays(graph.size(), 0);
        vector<long> distances(graph.size(), LONG_MAX);
        numberOfWays[source] = 1;
        distances[source] = 0;
        
        using P = pair<long, int>;
        priority_queue<P, vector<P>, greater<>> minHeap;
        minHeap.emplace(distances[source], source);
        
        while (!minHeap.empty()) {
            const auto [currentDistance, currentNode] = minHeap.top();
            minHeap.pop();
            
            if (currentDistance > distances[currentNode])
                continue;
            
            for (const auto& [neighbor, weight] : graph[currentNode]) {
                if (currentDistance + weight < distances[neighbor]) {
                    distances[neighbor] = currentDistance + weight;
                    numberOfWays[neighbor] = numberOfWays[currentNode];
                    minHeap.emplace(distances[neighbor], neighbor);
                } else if (currentDistance + weight == distances[neighbor]) {
                    numberOfWays[neighbor] += numberOfWays[currentNode];
                    numberOfWays[neighbor] %= kMod;
                }
            }
        }
        return numberOfWays[destination];
    }
};
