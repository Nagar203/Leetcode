#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string largestNumber(std::vector<int>& numbers) {
        std::string result;

        // Sort the numbers based on the custom comparison logic
        std::sort(numbers.begin(), numbers.end(), [](int num1, int num2) {
            return std::to_string(num1) + std::to_string(num2) > std::to_string(num2) + std::to_string(num1);
        });

        // Concatenate sorted numbers into the result string
        for (const int number : numbers) {
            result += std::to_string(number);
        }

        // If the largest number starts with '0', return "0"
        return result[0] == '0' ? "0" : result;
    }
};