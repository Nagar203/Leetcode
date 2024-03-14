#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int i = 0, j = 0;
        int result = 0;
        int window_sum = 0;
        int cnt_zeros = 0;

        while(j<n){
            window_sum += nums[j];
            while(i<j and (nums[i]==0 or window_sum > goal)){
                if(nums[i]==0){
                    cnt_zeros++;
                }
                else{
                    cnt_zeros = 0;
                }
                window_sum -= nums[i];
                i++;
            }
            if(window_sum == goal){
                result += 1 + cnt_zeros;
            }
            j++;
        }
        return result;
    }
};