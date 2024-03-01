#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = 0;
        int n = s.size();
        string result = "";
        
        for(int i=0; i<n; i++){
            cnt += s[i] - '0';
        }
        
        result = string(cnt-1,'1') + string(n-cnt,'0') + '1';
        return result;        
    }
};