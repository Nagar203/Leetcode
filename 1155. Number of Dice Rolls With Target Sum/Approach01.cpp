#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int MOD = 1e9+7;
    int t[31][1001];
    int solve(int n, int k, int target){
        if(target < 0){
            return 0;
        }
        if(t[n][target]!=-1){
            return t[n][target];
        }
        if(n==0){
            return target ==0;
        }
        int result = 0;
        for(int face=1; face<=k; face++){
            result = (result + solve(n-1, k, target-face))%MOD;
        }
        return t[n][target] = result;
    }

    int numRollsToTarget(int n, int k, int target) {
        memset(t,-1, sizeof(t)); 
        return solve(n,k,target);
    }
};