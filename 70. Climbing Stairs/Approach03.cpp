#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int n1 = 1;
        int n2 = 2;
        if(n==1 or n==2){return n;}
        for(int i=3; i<=n; i++){
            n2 = n1+n2;
            n1 = n2 - n1;
        }
        return n2;
    }
};