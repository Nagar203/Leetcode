#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int result1 = 0;
        int result2 = 0;

        for(int i=0; i<s.size(); i++){
            if(i%2 == 0 && s[i] != '0'){
                result1++;
            }
            else if(i%2 != 0 && s[i] != '1'){
                result1++;
            }

            if(i%2 == 0 && s[i] != '1'){
                result2++;
            }
            else if(i%2 != 0 && s[i] != '0'){
                result2++;
            }
        }
        return min(result1, result2);
    }
};