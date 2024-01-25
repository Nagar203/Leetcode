#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
    int t[1001][1001];
    int n1, n2;
    int solve(string& text1, string& text2, int i, int j){
        if(i>=n1 || j>=n2){
            return 0;
        }
        if(t[i][j]!= -1){
            return t[i][j];
        }
        if(text1[i]==text2[j]){
            return t[i][j] = 1 + solve(text1, text2, i+1, j+1);
        }
        return t[i][j] = max(solve(text1, text2, i+1, j), solve(text1, text2, i, j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        n1 = text1.size();
        n2 = text2.size();
        memset(t, -1, sizeof(t));
        return solve(text1, text2, 0, 0);
    }
};