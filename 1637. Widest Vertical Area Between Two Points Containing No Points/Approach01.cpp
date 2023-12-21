#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size();
        int result = -1;

        for(int i=0; i< n-1; i++){
            if((points[i+1][0] - points[i][0]) > result){
                result = points[i+1][0] - points[i][0];
            }
        }
        return result;
    }
};