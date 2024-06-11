#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int length = heights.size();
        int result = 0;
        vector<int> sorted_heights = heights;
        sort(sorted_heights.begin(), sorted_heights.end());

        for(int i=0; i<length; i++){
            if(heights[i] != sorted_heights[i]){
                result++;
            }
        }
        return result;
    }
};