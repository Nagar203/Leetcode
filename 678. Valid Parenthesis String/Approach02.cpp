#include <bits/stdc++.h>

using namespace std;

class Solution {
public: 
    
    bool checkValidString(string s) {
        int n = s.size();
        int t[102][102];
        memset(t, false, sizeof(t));
        t[n][0] = true;

        for(int index=n-1; index>=0; index--){
            for(int open=0; open<n; open++){
                bool is_valid = false;
                if(s[index] == '*'){
                    is_valid |= t[index+1][open+1];
                    is_valid |= t[index+1][open];
                    if(open > 0){
                        is_valid |= t[index+1][open-1];
                    }
                }
                else if (s[index] == '('){
                    is_valid |= t[index+1][open+1];
                }
                else if(open > 0){
                    is_valid |= t[index+1][open-1];
                }
                t[index][open] = is_valid;
            }
        }
        
        return t[0][0];
    }
};