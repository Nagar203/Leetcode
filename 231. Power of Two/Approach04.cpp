#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        int cnt = 0;
        while(n){
            if(n&1){
                cnt++;
            }
            n = n>>1;
            if(cnt==2){return false;}
        }
        return true;
    }
};