#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int t[101][101];
    bool solve(int index, int open, string &s, int n){
        if(index == n){
            return open == 0;
        }
        if(t[index][open] != -1){
            return t[index][open];
        }
        bool is_valid = false;
        if(s[index] == '*'){
            is_valid |= solve(index+1, open+1, s, n);
            is_valid |= solve(index+1, open, s, n);
            if(open > 0){
                is_valid |= solve(index+1, open-1, s, n);
            }
        }
        else if (s[index] == '('){
            is_valid |= solve(index+1, open+1, s, n);
        }
        else if(open > 0){
            is_valid |= solve(index+1, open-1, s, n);
        }
        return t[index][open] = is_valid;
    }

    bool checkValidString(string s) {
        int n = s.size();
        memset(t, -1, sizeof(t));
        return solve(0, 0, s, n);
    }
};