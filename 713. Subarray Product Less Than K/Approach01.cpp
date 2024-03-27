#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k<=1){
            return 0;
        }

        int result = 0;
        int i = 0, j = 0;
        int product = 1;

        while(j<n){
            product *= nums[j];
            while(product >= k){
                product /= nums[i];
                i++;
            }
            result = (j-i+1);
            j++;
        }

        return result;
    }
};