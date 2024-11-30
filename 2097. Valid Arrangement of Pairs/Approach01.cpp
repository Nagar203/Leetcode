#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
 public:
  vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    vector<vector<int>> result;
    unordered_map<int, stack<int>> adjacencyList;
    unordered_map<int, int> outDegree;
    unordered_map<int, int> inDegree;

    // Build graph and track in-degrees and out-degrees
    for (const vector<int>& pair : pairs) {
      int startNode = pair[0];
      int endNode = pair[1];
      adjacencyList[startNode].push(endNode);
      ++outDegree[startNode];
      ++inDegree[endNode];
    }

    // Get the starting node for Eulerian path
    int startNode = findStartNode(adjacencyList, outDegree, inDegree, pairs);

    // Perform Eulerian traversal
    eulerianTraversal(adjacencyList, startNode, result);

    // Reverse the result to get the correct order
    reverse(result.begin(), result.end());
    return result;
  }

 private:
  int findStartNode(const unordered_map<int, stack<int>>& adjacencyList,
                    unordered_map<int, int>& outDegree,
                    unordered_map<int, int>& inDegree,
                    const vector<vector<int>>& pairs) {
    for (const auto& [node, _] : adjacencyList)
      if (outDegree[node] - inDegree[node] == 1)
        return node;
    return pairs[0][0];  // Arbitrarily choose a node.
  }

  void eulerianTraversal(unordered_map<int, stack<int>>& adjacencyList, int currentNode,
                         vector<vector<int>>& result) {
    auto& nodeStack = adjacencyList[currentNode];
    while (!nodeStack.empty()) {
      int nextNode = nodeStack.top();
      nodeStack.pop();
      eulerianTraversal(adjacencyList, nextNode, result);
      result.push_back({currentNode, nextNode});
    }
  }
};