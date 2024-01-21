#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(101, -1);

        t[0] = 0;
        t[1] = nums[0];

        for(int i=2; i<=n; i++){
            int rob = nums[i-1] + t[i-2];
            int skip = t[i-1];

            t[i] = max(rob, skip);
        }
        return t[n];
    }
};