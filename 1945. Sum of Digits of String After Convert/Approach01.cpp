#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        string numericString = "";
        
        // Convert each character in the input string to its numeric equivalent
        for (char ch : s) {
            int numericValue = (ch - 'a' + 1);
            numericString += to_string(numericValue);
        }

        // Sum the digits for k iterations
        for (int i = 0; i < k; ++i) {
            int digitSum = 0;
            for (char digit : numericString) {
                digitSum += digit - '0'; // Convert character to integer
            }
            numericString = to_string(digitSum);
        }

        return stoi(numericString);
    }
};