#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int stepSize) {
        vector<int> flattenedGrid;

        for (const vector<int>& row : grid) {
            flattenedGrid.insert(flattenedGrid.end(), row.begin(), row.end());
        }

        if (ranges::any_of(flattenedGrid, [&](int value) { return (value - flattenedGrid[0]) % stepSize; })) {
            return -1;
        }

        int totalOperations = 0;

        nth_element(flattenedGrid.begin(), 
                    flattenedGrid.begin() + flattenedGrid.size() / 2, 
                    flattenedGrid.end());
        int medianValue = flattenedGrid[flattenedGrid.size() / 2];

        for (const int value : flattenedGrid) {
            totalOperations += abs(value - medianValue) / stepSize;
        }

        return totalOperations;
    }
};
