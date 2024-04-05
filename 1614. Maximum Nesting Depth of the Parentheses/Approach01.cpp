#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int result = 0;
        int cnt = 0;

        for(char &ch: s){
            if(ch == '('){
                cnt++;
            }
            else if(ch == ')'){
                cnt--;
            }
            result = max(result, cnt);
        }
        return result;

    }
};