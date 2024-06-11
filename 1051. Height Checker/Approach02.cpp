#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int length = heights.size();
        int current_height = 0;
        int result = 0;
        
        vector<int> height_count(101, 0);
        
        for (int height : heights) {
            height_count[height]++;
        }
                
        for (int i = 0; i < length; i++) {
            while (height_count[current_height] == 0) {
                current_height++;
            }
            if (heights[i] != current_height) {
                result++;
            }
            height_count[current_height]--;
        }
        
        return result;
    }
};
