#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int row;
    int col;
    int getMaximumGold(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int max_val = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] > 0) { 
                    max_val = max(solve(i, j, grid), max_val);
                }
            }
        }
        return max_val;
    }

private:
    int solve(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i == row || j == col || grid[i][j] == 0) {
            return 0;
        }
        int gold = grid[i][j];
        grid[i][j] = 0;

        int max_path = max(solve(i + 1, j, grid), max(solve(i - 1, j, grid), max(solve(i, j + 1, grid), solve(i, j - 1, grid))));

        grid[i][j] = gold; 
        return gold + max_path;
    }
};