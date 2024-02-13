#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(cnt==0){
                result = nums[i];
            }
            
            if(nums[i]==result){
                cnt++;
            }
            else if(nums[i]!=result){
                cnt--;
            }
        }
        return result;
    }
};