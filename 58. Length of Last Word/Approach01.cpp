#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int cnt =0, flag = 1;
        for(int i=n-1; i>=0; i--){
            if(s[i]!=' '){
                cnt++;
                flag = 0;
            }
            if(s[i]==' ' and flag == 0){
                return cnt;
            }
        }
        return cnt;
    }
};