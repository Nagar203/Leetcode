#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    vector<vector<int>> ans(m, vector<int>(n));
    
    vector<int> onesRow;
    vector<int> onesCol;

    for (const vector<int>& row : grid) {
        int countOnes = 0;
        for (int elem : row) {
            if (elem == 1) {
                countOnes++;
            }
        }
        onesRow.push_back(countOnes);
    }

    for (int j = 0; j < n; ++j) {
        int ones = 0;
        for (int i = 0; i < m; ++i) {
            ones += grid[i][j];
        }
        onesCol.push_back(ones);
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            ans[i][j] = onesRow[i] + onesCol[j] - (n - onesRow[i]) - (m - onesCol[j]);
        }
    }

    return ans;
  }
};