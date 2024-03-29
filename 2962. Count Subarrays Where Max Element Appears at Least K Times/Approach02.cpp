#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        ll result = 0;

        int max_val = -1;
        vector<int> max_ele_indexs;
        
        for(auto &it: nums){
            max_val = max(max_val, it);
        }    

        for(int i=0; i<n; i++){
            if(nums[i] == max_val){
                max_ele_indexs.push_back(i);
            }
            int size = max_ele_indexs.size();
            if(size>=k){
                int last_index = max_ele_indexs[size-k];
                result += (last_index + 1);
            }
        }

        return result;
    }
};