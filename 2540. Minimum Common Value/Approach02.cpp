#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j= 0;
        int n1 = nums1.size(), n2 = nums2.size();
        int result = INT_MAX;

        while(i<n1 and j<n2){
            if(nums1[i]== nums2[j]){
                result = min(result, nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return result != INT_MAX? result: -1;
    }
};