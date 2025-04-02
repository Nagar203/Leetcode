#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int maxPrefix = nums[0];  
        int maxDifference = INT_MIN;  
        long long maxTripletProduct = 0;  

        for (int j = 1; j < nums.size() - 1; ++j) {
            maxDifference = max(maxDifference, maxPrefix - nums[j]);  
            maxPrefix = max(maxPrefix, nums[j]);  
            maxTripletProduct = max(maxTripletProduct, static_cast<long long>(maxDifference) * nums[j + 1]);  
        }

        return maxTripletProduct;
    }
};