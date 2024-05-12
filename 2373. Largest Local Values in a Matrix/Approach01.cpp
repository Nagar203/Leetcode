#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int row = grid.size();
        vector<vector<int>> result;

        for(int i=0; i<row-2; i++){
            vector<int> temp_result;
            for(int j=0; j<row-2; j++){
                int val = max({grid[i][j], grid[i][j+1], grid[i][j+2], grid[i+1][j], grid[i+1][j+1], grid[i+1][j+2], grid[i+2][j], grid[i+2][j+1], grid[i+2][j+2]});
                temp_result.push_back(val);
            }
            result.push_back(temp_result);
        }
        return result;
    }
};