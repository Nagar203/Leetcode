#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> t(n + 1, vector<int>(k + 1, 0));

        for (int i = 0; i <= n; ++i) {
            t[i][0] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                t[i][j] = (t[i][j - 1] + t[i - 1][j]) % MOD;
                if (j - i >= 0) {
                    t[i][j] = (t[i][j] - t[i - 1][j - i] + MOD) % MOD;
                }
            }
        }
        return t[n][k];
    }
};