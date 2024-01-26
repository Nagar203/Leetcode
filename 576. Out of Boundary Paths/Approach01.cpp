#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef long long ll;
    ll MOD = 1000000007;
    ll t[51][51][51];

    int solve(int m, int n, int max_move, int start_row, int start_column) {
        if (start_row < 0 or start_row >= m or start_column < 0 or start_column >= n) {
            return 1;
        }
        if (max_move == 0) {
            return 0;
        }
        if (t[start_row][start_column][max_move] != -1) {
            return t[start_row][start_column][max_move];
        }
        vector<pair<int, int>> direction{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        ll result = 0;

        for (auto it : direction) {
            result = (result + solve(m, n, max_move - 1, start_row + it.first, start_column + it.second)) % MOD;
        }
        return t[start_row][start_column][max_move] = result;
    }

    int findPaths(int m, int n, int max_move, int start_row, int start_column) {
        memset(t, -1, sizeof(t));
        return solve(m, n, max_move, start_row, start_column);
    }
};
