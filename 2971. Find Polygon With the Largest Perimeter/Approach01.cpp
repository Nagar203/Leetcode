#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef long long ll;
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        ll result = 0, total = 0;

        for(int i=0; i<n; i++){
            if(nums[i] < total){
                result = total + nums[i];
            }
            total += nums[i];
        }
        return result==0? -1: result;
    }
};