#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();

        for(int i=0; i<nums.size(); i++){
            auto it = lower_bound(begin(result), end(result), nums[i]);
            if(it == end(result)){
                result.push_back(nums[i]);
            }
            else{
                *it = nums[i];
            }
        }
        return result.size();
    }
};