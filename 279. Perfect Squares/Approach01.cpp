#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool is_perfect_square(int n){
        int val = pow(n,0.5);
        return n == val*val;
    }

    int numSquares(int n) {
        if(is_perfect_square(n)){
            return 1;
        }    
        
        while(n%4 == 0){
            n = n/4;
        }

        if(n%8 == 7){
            return 4;
        }
        
        for(int i=1; i*i<n; i++){
            if(is_perfect_square(n-i*i)){
                return 2;
            }
        }
        return 3;
    }
};