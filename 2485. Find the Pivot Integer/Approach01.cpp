#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        if(n==1) return n;
        if(n==2) return -1;

        int total = (n*(n+1))/2;
        int mid = n/2;
        int i=1;
        while(i<=n){
            int temp_sum = (i*(i+1))/2;
            int rem_sum = total - temp_sum + i;
            if(rem_sum < temp_sum){
                return -1;
            }
            if(rem_sum == temp_sum){
                return i;
            }
            else if(rem_sum > temp_sum){
                i++;
            }
        }
        return -1;
    }
};