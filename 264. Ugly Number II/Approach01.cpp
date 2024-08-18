#include <vector>
#include <algorithm>

class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> uglyNumbers{1};  // Vector to store ugly numbers
        int index2 = 0;  // Pointer for multiples of 2
        int index3 = 0;  // Pointer for multiples of 3
        int index5 = 0;  // Pointer for multiples of 5

        while (uglyNumbers.size() < n) {
            const int nextMultipleOf2 = uglyNumbers[index2] * 2;
            const int nextMultipleOf3 = uglyNumbers[index3] * 3;
            const int nextMultipleOf5 = uglyNumbers[index5] * 5;
            const int nextUglyNumber = std::min({nextMultipleOf2, nextMultipleOf3, nextMultipleOf5});
            
            if (nextUglyNumber == nextMultipleOf2)
                ++index2;
            if (nextUglyNumber == nextMultipleOf3)
                ++index3;
            if (nextUglyNumber == nextMultipleOf5)
                ++index5;
                
            uglyNumbers.push_back(nextUglyNumber);
        }

        return uglyNumbers.back();  // Return the nth ugly number
    }
};
