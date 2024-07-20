#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        // Iterate through each row in the matrix
        for (const vector<int>& row : matrix) {
            // Find the index of the minimum element in the current row
            const int minElementIndex = distance(row.begin(), ranges::min_element(row));

            // Check if the minimum element in the row is the maximum element in
            // its column
            if (row[minElementIndex] == getMaxOfColumn(matrix, minElementIndex)){
                return {row[minElementIndex]};
            }
                
        }
        // Return an empty vector if no lucky number is found
        return {};
    }

private:
    // Helper function to find the maximum element in a specified column
    int getMaxOfColumn(const vector<vector<int>>& matrix, int colIndex) {
        int maxElement = 0;
        // Iterate through each row to find the maximum element in the column
        for (int rowIndex = 0; rowIndex < matrix.size(); ++rowIndex){
            maxElement = max(maxElement, matrix[rowIndex][colIndex]);
        }
        return maxElement;
    }
};
