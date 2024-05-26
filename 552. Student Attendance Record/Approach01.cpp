#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9 + 7;
        vector<vector<long>> t(2, vector<long>(3));
        t[0][0] = 1;

        while (n--) {
            const auto prev(t); 
            t[0][0] = (prev[0][0] + prev[0][1] + prev[0][2]) % MOD;
            t[0][1] = prev[0][0];
            t[0][2] = prev[0][1];
            t[1][0] = (prev[0][0] + prev[0][1] + prev[0][2] + prev[1][0] + prev[1][1] + prev[1][2])%MOD;
            t[1][1] = prev[1][0];
            t[1][2] = prev[1][1];
        }

        return accumulate(t.begin(), t.end(), 0L, [MOD](long s, vector<long>& row) {return (s + accumulate(row.begin(), row.end(), 0L)) % MOD;});
    }
};
