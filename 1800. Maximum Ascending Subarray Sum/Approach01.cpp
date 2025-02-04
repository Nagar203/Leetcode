#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = INT_MIN;
        int arraySize = nums.size();

        for (int i = 1; i < arraySize; i++) {
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i];
            } else {
                maxSum = max(maxSum, currentSum);
                currentSum = nums[i];
            }
        }
        
        return max(maxSum, currentSum);
    }
};