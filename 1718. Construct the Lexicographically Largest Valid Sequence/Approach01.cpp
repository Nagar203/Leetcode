#include <vector>

class Solution {
public:
    // Helper function to find the largest lexicographical sequence
    bool findLargestSequence(std::vector<int>& sequence, std::vector<bool>& isUsed, int index, int n) {
        if (index == (2 * n - 1)) {
            return true;
        }
        if (sequence[index] != 0) {
            return findLargestSequence(sequence, isUsed, index + 1, n);
        }
        
        for (int num = n; num >= 1; --num) {
            if (isUsed[num]) continue;
            isUsed[num] = true;
            sequence[index] = num;

            if (num == 1) {
                if (findLargestSequence(sequence, isUsed, index + 1, n)) return true;
            } 
            else if ((index + num) < (2 * n - 1) && sequence[index + num] == 0) {
                sequence[index + num] = num;
                if (findLargestSequence(sequence, isUsed, index + 1, n)) return true;
                sequence[index + num] = 0; 
            }

            isUsed[num] = false; 
            sequence[index] = 0;
        }
        return false;
    }

    // Main function to construct the lexicographically largest sequence
    std::vector<int> constructDistancedSequence(int n) {
        std::vector<int> sequence(2 * n - 1, 0);
        std::vector<bool> isUsed(n + 1, false);
        findLargestSequence(sequence, isUsed, 0, n);
        return sequence;
    }
};