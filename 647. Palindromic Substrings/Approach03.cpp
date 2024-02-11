#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int result;
    void solve(string& s, int i, int j, int n){
        while( i>=0 && j<n && s[i]==s[j]){
            result++;
            i--;
            j++;
        }
    }
    int countSubstrings(string s) {
        int n = s.size();
        result = 0;

        for(int i=0; i<n; i++){
            solve(s, i, i, n);
            solve(s, i, i+1, n);
        }
        return result;
    }
};