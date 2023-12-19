#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int row = img.size();
        int col = img[0].size();
        vector<vector<int>> result(row, vector<int>(col));

        if(row==1 && col ==1) return img;
        

        for(int i=0; i< row; i++){
            for(int j=0; j < col; j++){

                if(col > 0  && row ==1){
                    if(j==0){
                        result[i][j] = (img[i][j] + img[i][j+1])/2;
                    }
                    else if(j == col-1){
                        result[i][j] = (img[i][j] + img[i][j-1])/2;
                    }
                    else{
                        result[i][j] = (img[i][j] + img[i][j-1] + img[i][j+1])/3;
                    }
                }

                else if(row > 0  && col ==1){
                    if(i==0){
                        result[i][j] = (img[i][j] + img[i+1][j])/2;
                    }
                    else if(i == row-1){
                        result[i][j] = (img[i][j] + img[i-1][j])/2;
                    }
                    else{
                        result[i][j] = (img[i][j] + img[i-1][j] + img[i+1][j])/3;
                    }
                }


                else if((i > 0 && j > 0) && (i < (row-1) && j < (col-1))){
                    result[i][j] = (img[i][j] + img[i+1][j] + img[i-1][j] + img[i][j+1] + img[i][j-1] + img[i-1][j-1] + img[i+1][j-1] + img[i-1][j+1] + img[i+1][j+1])/9;
                }
                else if((i == 0 && j == 0) || (i == 0 && j == col-1) || (i == row-1 && j == 0) || (i == row-1 && j == col-1)) {
                    if(i == 0 && j == 0) {
                        result[i][j] = (img[i][j] + img[i+1][j] + img[i][j+1] + img[i+1][j+1])/4;
                    }
                    else if(i == 0 && j == col-1){
                        result[i][j] = (img[i][j] + img[i+1][j] + img[i][j-1] + img[i+1][j-1])/4;
                    }
                    else if(i == row-1 && j == 0){
                        result[i][j] = (img[i][j] + img[i-1][j] + img[i][j+1] + img[i-1][j+1])/4;
                    }
                    else if(i == row-1 && j == col-1) {
                        result[i][j] = (img[i][j] + img[i-1][j] + img[i][j-1] + img[i-1][j-1])/4;
                    }
                }
                else if( i > 0 && i < row-1 && j == 0){
                    result[i][j] = (img[i][j] + img[i-1][j] + img[i][j+1] + img[i-1][j+1] + img[i+1][j] + img[i+1][j+1])/6;
                }
                else if( i > 0 && i < row-1 && j == col-1){
                    result[i][j] = (img[i][j] + img[i-1][j] + img[i][j-1] + img[i-1][j-1] + img[i+1][j] + img[i+1][j-1])/6;
                }

                else if( j > 0 && j < col-1 && i == 0){
                    result[i][j] = (img[i][j] + img[i+1][j] + img[i][j+1] + img[i+1][j+1] + img[i+1][j-1] + img[i][j-1])/6;
                }
                else if( j > 0 && j < col-1 && (i == row-1)){
                    result[i][j] = (img[i][j] + img[i][j+1] + img[i][j-1] + img[i-1][j-1] + img[i-1][j+1] + img[i-1][j])/6;
                }
            }
        }
        return result;
    }
};