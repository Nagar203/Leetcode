#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    int t[501];
    int solve(int i, vector<int>& arr, int k){
        if(i>=n){
            return 0;
        }

        if(t[i] != -1){
            return t[i];
        }

        int result = 0;
        int max_val = -1;

        for(int j=i; j<n and (j-i+1) <=k; j++){
            max_val = max(arr[j], max_val);
            result = max(max_val*(j-i+1) + solve(j+1, arr, k), result);
        }

        return t[i] = result;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(t, -1, sizeof(t));
        return solve(0, arr, k);
        
    }
};
