#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int subIslandsCount = 0;

        for (int row = 0; row < grid2.size(); ++row) {
            for (int col = 0; col < grid2[0].size(); ++col) {
                if (grid2[row][col] == 1) {
                    subIslandsCount += exploreIsland(grid1, grid2, row, col);
                }
            }
        }
        return subIslandsCount;
    }

private:
    int exploreIsland(const vector<vector<int>>& grid1, vector<vector<int>>& grid2, int row, int col) {
        if (row < 0 || row == grid1.size() || col < 0 || col == grid2[0].size()) {
            return 1;
        }
        if (grid2[row][col] != 1) {
            return 1;
        }

        grid2[row][col] = 2; // Mark as visited
        return exploreIsland(grid1, grid2, row + 1, col) & 
               exploreIsland(grid1, grid2, row - 1, col) & 
               exploreIsland(grid1, grid2, row, col + 1) & 
               exploreIsland(grid1, grid2, row, col - 1) & 
               grid1[row][col];
    }
};
