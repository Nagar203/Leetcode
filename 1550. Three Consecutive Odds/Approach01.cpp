#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int result = 0;

        for(int i=0; i < arr.size(); i++){
            int n = arr[i];
            if(n%2 != 0){
                result++;
            }
            else{
                result = 0;
            }
            if(result == 3){
                return true;
            }
        }
        return false;
    }
};