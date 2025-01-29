#include <vector>
#include <numeric>
using namespace std;

class UnionFind {
 public:
  UnionFind(int size) : parent(size), rank(size) {
    iota(parent.begin(), parent.end(), 0); // Initialize each node as its own parent
  }

  bool unionByRank(int node1, int node2) {
    int root1 = find(node1);
    int root2 = find(node2);

    if (root1 == root2)  
      return false;  // Cycle detected

    // Union by rank
    if (rank[root1] < rank[root2]) {
      parent[root1] = root2;
    } else if (rank[root1] > rank[root2]) {
      parent[root2] = root1;
    } else {
      parent[root1] = root2;
      ++rank[root2];
    }

    return true;
  }

 private:
  vector<int> parent;
  vector<int> rank;

  int find(int node) {
    return parent[node] == node ? node : parent[node] = find(parent[node]);  // Path compression
  }
};

class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    UnionFind unionFind(edges.size() + 1);

    for (const vector<int>& edge : edges) {
      int node1 = edge[0];
      int node2 = edge[1];

      if (!unionFind.unionByRank(node1, node2))  // If adding this edge forms a cycle
        return edge;
    }

    throw;  // This should never be reached
  }
};
