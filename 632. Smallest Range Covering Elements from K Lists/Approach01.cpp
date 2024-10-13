#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Element {
  int rowIndex;
  int colIndex;
  int value;  // nums[rowIndex][colIndex]
};

class Solution {
 public:
  vector<int> smallestRange(vector<vector<int>>& numLists) {
    auto compare = [&](const Element& a, const Element& b) { return a.value > b.value; };
    priority_queue<Element, vector<Element>, decltype(compare)> minHeap(compare);
    int currentMin = INT_MAX;
    int currentMax = INT_MIN;

    // Initialize the heap with the first element from each list
    for (int i = 0; i < numLists.size(); ++i) {
      const int value = numLists[i][0];
      minHeap.emplace(Element{i, 0, value});
      currentMin = min(currentMin, value);
      currentMax = max(currentMax, value);
    }

    int minRange = currentMin;
    int maxRange = currentMax;

    // Continue processing until the heap contains elements from all lists
    while (minHeap.size() == numLists.size()) {
      const auto [rowIndex, colIndex, _] = minHeap.top();
      minHeap.pop();
      
      if (colIndex + 1 < numLists[rowIndex].size()) {
        minHeap.emplace(Element{rowIndex, colIndex + 1, numLists[rowIndex][colIndex + 1]});
        currentMax = max(currentMax, numLists[rowIndex][colIndex + 1]);
        currentMin = minHeap.top().value;
        
        if (currentMax - currentMin < maxRange - minRange) {
          minRange = currentMin;
          maxRange = currentMax;
        }
      }
    }

    return {minRange, maxRange};
  }
};