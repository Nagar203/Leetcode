#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int islandCount = 0;  // To count the number of connected components (islands)
        vector<vector<int>> adjacencyList(stones.size());  // Graph represented as an adjacency list
        unordered_set<int> visitedNodes;  // Set to keep track of visited nodes

        // Building the graph by connecting nodes that are in the same row or column
        for (int i = 0; i < stones.size(); ++i) {
            for (int j = i + 1; j < stones.size(); ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adjacencyList[i].push_back(j);
                    adjacencyList[j].push_back(i);
                }
            }
        }

        // DFS to count the number of islands (connected components)
        for (int i = 0; i < stones.size(); ++i) {
            if (visitedNodes.insert(i).second) {  // If node i is not visited
                exploreConnectedComponent(adjacencyList, i, visitedNodes);
                ++islandCount;  // Increment the count of islands
            }
        }

        // The answer is the total number of stones minus the number of connected components
        return stones.size() - islandCount;
    }

private:
    void exploreConnectedComponent(const vector<vector<int>>& adjacencyList, int node, unordered_set<int>& visitedNodes) {
        for (const int adjacentNode : adjacencyList[node]) {
            if (visitedNodes.insert(adjacentNode).second) {  // If adjacentNode is not visited
                exploreConnectedComponent(adjacencyList, adjacentNode, visitedNodes);  // Continue DFS
            }
        }
    }
};