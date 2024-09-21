#include <unordered_set>
#include <vector>

class Solution {
public:
    vector<int> lexicalOrder(int maxNumber) {
        vector<int> result;
        int currentNumber = 1;

        // Generate numbers in lexicographical order
        while (result.size() < maxNumber) {
            result.push_back(currentNumber);
            if (currentNumber * 10 <= maxNumber) {
                currentNumber *= 10;
            } else {
                while (currentNumber % 10 == 9 || currentNumber == maxNumber)
                    currentNumber /= 10;
                ++currentNumber;
            }
        }

        return result;
    }
};