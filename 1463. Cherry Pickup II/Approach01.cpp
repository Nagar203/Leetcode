#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    int t[71][71][71];

    Solution() {}

    int solve(vector<vector<int>>& grid, int row, int col1, int col2) {
        if (row >= m)
            return 0;

        if (t[row][col1][col2] != -1)
            return t[row][col1][col2];

        int cherry = grid[row][col1];
        if (col1 != col2)
            cherry += grid[row][col2];

        int direction[] = {-1, 0, 1};
        int result = 0;
        for (int i : direction) {
            for (int j : direction) {
                if (0 <= col1 + i && col1 + i < n && 0 <= col2 + j && col2 + j < n) {
                    result = max(result, solve(grid, row + 1, col1 + i, col2 + j));
                }
            }
        }
        t[row][col1][col2] = result + cherry;
        return result + cherry;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t, -1, sizeof(t));
        int output = solve(grid, 0, 0, n - 1);
        return output;
    }
};
