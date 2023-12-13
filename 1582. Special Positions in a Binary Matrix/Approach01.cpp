#include <vector>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int result = 0;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(mat[i][j] == 1){
                    int check_row = 0;
                    int check_col = 0;
                    int row_sum = 0;
                    int col_sum = 0;
                    
                    while(check_row < row){
                        row_sum += mat[check_row][j];
                        check_row++;
                    }
                    
                    while(check_col < col){
                        col_sum += mat[i][check_col];
                        check_col++;
                    }
                    
                    if(col_sum == 1 && row_sum == 1){
                        result++;
                    }

                }
            }
        }
        return result;
    }
};