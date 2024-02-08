#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int t[10002];
    
    int solve(int n){
        if(n==0){
            return 0;
        }
        if(t[n]!=-1){
            return t[n];
        }
        int result = 0;
        int min_cnt = INT_MAX;
        for(int i=1; i*i<=n; i++){
            result = 1 + solve(n-i*i);
            min_cnt = min(min_cnt, result);
        }
        return t[n] = min_cnt;
    }

    int numSquares(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};