#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        
        vector<int> t(n+1, 100000);
        t[0] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j*j<=i; j++){
                t[i] = min(t[i],1 + t[i-j*j]);
            }
        }
        return t[n];
    }
};