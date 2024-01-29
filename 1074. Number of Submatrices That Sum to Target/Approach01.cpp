#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int row=0; row<rows; row++){
            for(int col=1; col<cols; col++){
                matrix[row][col] += matrix[row][col-1];
            }
        }

        int result = 0;
        for(int start_col =0; start_col<cols; start_col++){
            for(int i=start_col; i<cols; i++){

                unordered_map<int, int> mp;
                mp.insert({0,1});
                int index_sum = 0;
                
                for(int row=0; row<rows; row++){
                    index_sum += matrix[row][i] - ((start_col>0)?matrix[row][start_col-1]: 0);
                    if(mp.find(index_sum - target) != mp.end()){
                        result += mp[index_sum - target];
                    }
                    mp[index_sum]++;
                }                
            }
        }
        return result;
    }
};