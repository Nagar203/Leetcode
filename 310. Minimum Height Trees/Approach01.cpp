#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1 || edges.empty())
      return {0};

    vector<int> result;
    unordered_map<int, unordered_set<int>> graph;

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].insert(v);
      graph[v].insert(u);
    }

    for (const auto& [label, children] : graph)
      if (children.size() == 1)
        result.push_back(label);

    while (n > 2) {
      n -= result.size();
      vector<int> nextLeaves;
      for (const int leaf : result) {
        const int u = *graph[leaf].begin();
        graph[u].erase(leaf);
        if (graph[u].size() == 1)
          nextLeaves.push_back(u);
      }
      result = nextLeaves;
    }

    return result;
  }
};