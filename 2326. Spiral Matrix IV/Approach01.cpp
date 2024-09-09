#include <unordered_set>
#include <vector>

class Solution {
public:
    vector<vector<int>> spiralMatrix(int rows, int cols, ListNode* head) {
        // Directions for moving right, down, left, up
        constexpr int directionOffsets[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> matrix(rows, vector<int>(cols, -1));

        int currentRow = 0;     // Current row position
        int currentCol = 0;     // Current column position
        int directionIndex = 0; // Current direction index

        for (ListNode* node = head; node; node = node->next) {
            matrix[currentRow][currentCol] = node->val;

            // Check if we need to change direction
            if (currentRow + directionOffsets[directionIndex][0] < 0 ||
                currentRow + directionOffsets[directionIndex][0] == rows ||
                currentCol + directionOffsets[directionIndex][1] < 0 ||
                currentCol + directionOffsets[directionIndex][1] == cols ||
                matrix[currentRow + directionOffsets[directionIndex][0]] [currentCol + directionOffsets[directionIndex][1]] != -1) {
                directionIndex = (directionIndex + 1) % 4;
            }

            currentRow += directionOffsets[directionIndex][0];
            currentCol += directionOffsets[directionIndex][1];
        }

        return matrix;
    }
};