#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &it: nums){
            mp[it] = 1;
        }

        int n = mp.size();
        for(int i=1; i<n+2; i++){
            if(mp[i] != 1){
                return i;
            }
        }
        return -1;
    }
};