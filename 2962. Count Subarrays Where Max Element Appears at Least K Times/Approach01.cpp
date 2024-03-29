#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        ll result = 0;
        unordered_map<int, int> mp;
        int max_val = -1;
        int cnt_max = 0;
        
        for(auto &it: nums){
            max_val = max(max_val, it);
        }    

        while(j<n){
            if(nums[j] == max_val){
                cnt_max++;
            }
            while(cnt_max >= k){
                result += (n-j);
                if(nums[i] == max_val){
                    cnt_max--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
};