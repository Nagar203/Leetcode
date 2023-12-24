#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        string string1 = "";
        string string2 = "";

        int result1 = 0;
        int result2 = 0;

        for(int i=0; i<s.size(); i++){
            if(i%2 == 0){
                string1 = string1 + '0';
                string2 = string2 + '1';
            }
            else{
                string1 = string1 + '1';
                string2 = string2 + '0';
            }
        }

        for(int i=0; i<s.size(); i++){
            if(s[i] != string1[i]){
                result1++;
            }
            if(s[i] != string2[i]){
                result2++;
            }
        }
        return min(result1, result2);
    }
};