#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;

        for (int i = 0; i < land.size(); ++i)
            for (int j = 0; j < land[0].size(); ++j)
                if (land[i][j] == 1) {
                    int x = i;
                    int y = j;
                    dfs(land, i, j, x, y);
                    result.push_back({i, j, x, y});
                }

        return result;
    }

private:
    void dfs(vector<vector<int>>& land, int i, int j, int& x, int& y) {
        if (i < 0 || i == land.size() || j < 0 || j == land[0].size())
            return;
        if (land[i][j] != 1)
            return;
        land[i][j] = 2;
        x = max(x, i);
        y = max(y, j);
        dfs(land, i + 1, j, x, y);
        dfs(land, i, j + 1, x, y);
    }
};