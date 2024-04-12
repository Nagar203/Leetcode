#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getLeftSideArray(vector<int>& height, int n) {
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {  
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        return leftMax;
    }

    vector<int> getRightSideArray(vector<int>& height, int n) {
        vector<int> rightMax(n);
        rightMax[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {  
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        return rightMax;
    }

    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax = getLeftSideArray(height, n);
        vector<int> rightMax = getRightSideArray(height, n);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            int h = min(leftMax[i], rightMax[i]) - height[i];
            sum += max(h, 0);
        }
        return sum;
    }
};