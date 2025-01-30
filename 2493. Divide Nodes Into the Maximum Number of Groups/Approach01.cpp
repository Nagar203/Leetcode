#include <vector>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;

class UnionFind {
 public:
  UnionFind(int size) : parent(size), rank(size) {
    iota(parent.begin(), parent.end(), 0);  // Initialize each node as its own parent
  }

  void unionByRank(int node1, int node2) {
    int root1 = find(node1);
    int root2 = find(node2);

    if (root1 == root2)
      return;

    // Union by rank
    if (rank[root1] < rank[root2]) {
      parent[root1] = root2;
    } else if (rank[root1] > rank[root2]) {
      parent[root2] = root1;
    } else {
      parent[root1] = root2;
      ++rank[root2];
    }
  }

  int find(int node) {
    return parent[node] == node ? node : parent[node] = find(parent[node]);  // Path compression
  }

 private:
  vector<int> parent;
  vector<int> rank;
};

class Solution {
 public:
  int magnificentSets(int numNodes, vector<vector<int>>& edges) {
    vector<vector<int>> adjacencyList(numNodes);
    UnionFind unionFind(numNodes);
    unordered_map<int, int> rootToMaxGroupSize;

    // Build adjacency list and perform union-find operations
    for (const vector<int>& edge : edges) {
      int node1 = edge[0] - 1;
      int node2 = edge[1] - 1;
      adjacencyList[node1].push_back(node2);
      adjacencyList[node2].push_back(node1);
      unionFind.unionByRank(node1, node2);
    }

    // Perform BFS to determine the maximum valid group size
    for (int i = 0; i < numNodes; ++i) {
      int maxGroupSize = bfs(adjacencyList, i);
      if (maxGroupSize == -1)
        return -1;  // Odd cycle detected

      int root = unionFind.find(i);
      rootToMaxGroupSize[root] = max(rootToMaxGroupSize[root], maxGroupSize);
    }

    int totalGroups = 0;
    for (const auto& [_, maxGroupSize] : rootToMaxGroupSize)
      totalGroups += maxGroupSize;

    return totalGroups;
  }

 private:
  int bfs(const vector<vector<int>>& adjacencyList, int startNode) {
    int depth = 0;
    queue<int> nodeQueue{{startNode}};
    unordered_map<int, int> nodeDepthMap{{startNode, 1}};

    while (!nodeQueue.empty()) {
      ++depth;
      for (int size = nodeQueue.size(); size > 0; --size) {
        int currentNode = nodeQueue.front();
        nodeQueue.pop();
        for (int neighbor : adjacencyList[currentNode]) {
          if (!nodeDepthMap.contains(neighbor)) {
            nodeQueue.push(neighbor);
            nodeDepthMap[neighbor] = depth + 1;
          } else if (nodeDepthMap[neighbor] == depth) {
            return -1;  // Odd-length cycle detected
          }
        }
      }
    }

    return depth;
  }
};