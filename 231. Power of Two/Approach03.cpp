#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        int cnt = 0;
        for(int i=0; i<=30; i++){
            if(n&1){
                cnt++;
            }
            n>>=1;
        }
        return cnt==1?true:false;
    }
};