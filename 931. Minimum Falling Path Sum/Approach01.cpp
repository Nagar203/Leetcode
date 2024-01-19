#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<vector<int>> t(m, vector<int>(m));
        
        for(int col = 0; col<m; col++) {
            t[0][col] = matrix[0][col];
        }
        
        for(int row = 1; row < m; row++) {
            for(int col = 0; col < m; col++) {
                t[row][col] = matrix[row][col] + min({t[row-1][col], t[row-1][max(0, col-1)],  t[row-1][min(m-1, col+1)]});
            }
        }

        return *min_element(t[m-1].begin(), t[m-1].end());
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) { 
        return solve(matrix);
    }
};