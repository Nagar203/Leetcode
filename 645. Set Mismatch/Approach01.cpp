#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int flag=1;
        int repeat = -1;
        int missing_num = -1;
        set<int> s;

        sort(nums.begin(), nums.end());

        for (int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                repeat = nums[i];
                break;
            }
            s.insert(nums[i]);
        }
        
        s.insert(nums[n-1]);

        int i=1;
        
        for (auto it=s.begin(); it!= s.end(); it++){
            if(i != *it){
                missing_num = i;
                break;
            }
            i++;
        }
        
        if(missing_num == -1){ missing_num = n; }
       
        return {repeat, missing_num};
    }
};