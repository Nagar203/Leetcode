#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int MOD = 1e9+7;

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> t(n + 1, vector<int>(target + 1));
        t[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                int result = 0;
                for (int face = 1; face <= k; face++) {
                    if (j >= face) {
                        result = (result + t[i - 1][j - face]) % MOD;
                    }
                }
                t[i][j] = result;
            }
        }
        return t[n][target];
    }
};