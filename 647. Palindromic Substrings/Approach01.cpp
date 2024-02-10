#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int result = n;

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                string sub_str = s.substr(i,j+1-i);
                string rev_sub_str = sub_str;
                reverse(rev_sub_str.begin(), rev_sub_str.end()); 
                if(rev_sub_str == sub_str){
                    result++;
                }
            }
        }
        return result;
    }
};