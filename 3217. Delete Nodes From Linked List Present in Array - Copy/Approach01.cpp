#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int maxRampWidth = 0;
        stack<int> indexStack;

        // First pass: find the indices of decreasing elements
        for (int i = 0; i < nums.size(); ++i) {
            if (indexStack.empty() || nums[i] < nums[indexStack.top()]) {
                indexStack.push(i);
            }
        }

        // Second pass: check for the maximum ramp width
        for (int i = nums.size() - 1; i > maxRampWidth; --i) {
            while (!indexStack.empty() && nums[i] >= nums[indexStack.top()]) {
                maxRampWidth = max(maxRampWidth, i - indexStack.top());
                indexStack.pop();
            }
        }

        return maxRampWidth;
    }
};