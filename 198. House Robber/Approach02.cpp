#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int index, int n){
        if(index>=n){
            return 0;
        }

        if(t[index] != -1){
            return t[index];
        }

        int rob = nums[index] + solve(nums, index+2, n);
        int skip = solve(nums, index+1, n);

        return t[index] = max(rob, skip);
    }
    int rob(vector<int>& nums) {
       int n = nums.size();
        memset(t, -1, sizeof(t));
       return solve(nums, 0, n); 
    }
};