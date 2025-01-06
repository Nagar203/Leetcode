#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> operationsResult(n, 0);  // Stores the final operations count for each box
        int ballCount = 0;  // Tracks the number of balls ('1's) encountered so far
        int currentOperations = 0;  // Tracks the cumulative operations while traversing

        // Traverse from left to right
        for (int i = 0; i < n; ++i) {
            operationsResult[i] += currentOperations;
            ballCount += (boxes[i] - '0');  // Increment ball count if the box has a ball
            currentOperations += ballCount;  // Update the number of operations
        }

        ballCount = 0;
        currentOperations = 0;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; --i) {
            operationsResult[i] += currentOperations;
            ballCount += (boxes[i] - '0');  // Increment ball count if the box has a ball
            currentOperations += ballCount;  // Update the number of operations
        }

        return operationsResult;
    }
};