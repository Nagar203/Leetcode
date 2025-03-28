#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> result(queries.size(), 0);
        vector<pair<int, int>> indexedQueries;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        set<pair<int, int>> visitedCells;
        int pointsCollected = 0;
        vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < queries.size(); ++i) {
            indexedQueries.push_back({queries[i], i});
        }
        sort(indexedQueries.begin(), indexedQueries.end());
        minHeap.push({grid[0][0], {0, 0}});
        visitedCells.insert({0, 0});
        for (auto [queryValue, queryIndex] : indexedQueries) {
            while (!minHeap.empty()) {
                auto [cellValue, cellPos] = minHeap.top();
                int rowIndex = cellPos.first;
                int colIndex = cellPos.second;
                if (cellValue >= queryValue) {
                    break;
                }
                minHeap.pop();
                pointsCollected++;
                for (auto [dRow, dCol] : DIRECTIONS) {
                    int newRow = rowIndex + dRow;
                    int newCol = colIndex + dCol;
                    if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                        continue;
                    }
                    if (visitedCells.count({newRow, newCol})) {
                        continue;
                    }
                    minHeap.push({grid[newRow][newCol], {newRow, newCol}});
                    visitedCells.insert({newRow, newCol});
                }
            }
            result[queryIndex] = pointsCollected;
        }
        return result;
    }
};