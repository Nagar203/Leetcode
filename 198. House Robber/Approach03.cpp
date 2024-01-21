#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int first_val = nums[0];
        int second_val = 0;
        
        for(int i=2; i<=n; i++){
            int rob = nums[i-1] + second_val;
            int skip = first_val;
            int temp = max(rob, skip);
            second_val = first_val;
            first_val = temp;            
        }
        return first_val;
    }
};