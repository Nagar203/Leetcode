#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int repeat_val = -1;
        int missing_val = -1;
        int flag1=1, flag2=1, cnt=1;
        
        map<int, int> mp;

        for(auto i: nums){
            mp[i]++;
        }
        
        for(auto it: mp){
            if(it.second==2 and flag1==1){
                repeat_val = it.first;
                flag1 = 0;
            }
            if(it.first != cnt and flag2==1){
                missing_val = cnt;
                flag2=0;
            }
            if(flag2){
                cnt++;
            }            
        }
        
        if(missing_val == -1){ missing_val = n; }
       
        return {repeat_val, missing_val};
    }
};