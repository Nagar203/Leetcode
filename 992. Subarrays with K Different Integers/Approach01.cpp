#include <bits/stdc++.h>

using namespace std;

#include <vector>
#include <unordered_map>

class Solution {
public:
    
    int slidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        int n = nums.size();
        int start = 0; 
        int end = 0;
        
        int result = 0;
        
        while(end < n) {
            mp[nums[end]]++;
            
            while(mp.size() > k) {
                mp[nums[start]]--;
                if(mp[nums[start]] == 0) {
                    mp.erase(nums[start]);
                }
                start++;
            }
            
            result += (end - start + 1); 
            end++;
        }
        
        return result;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k - 1);
    }
};
