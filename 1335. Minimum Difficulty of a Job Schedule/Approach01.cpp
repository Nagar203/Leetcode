#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n<d){
            return -1;
        }
        vector<vector<int>> t(n, vector<int>(d+1, -1));

        for(int i=0; i<n ; i++){
            t[i][1] = *max_element(begin(jobDifficulty)+i, end(jobDifficulty) );
        }

        for(int days=2; days <= d; days++){
            for(int i=0; i<=n-days; i++){
                int max_data = INT_MIN;
                int result = INT_MAX;

                for(int j=i; j<=n-days; j++){
                    max_data = max(max_data, jobDifficulty[j]);
                    result = min(result, max_data + t[j+1][days-1]);
                }
                t[i][days] = result;
            }
        }
        return t[0][d];
    }
};