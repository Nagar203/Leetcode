#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int minLength(string inputString) {
        stack<char> charStack;

        for (const char currentChar : inputString) {
            if (currentChar == 'B' && isMatchingPair(charStack, 'A')) {
                charStack.pop();
            } else if (currentChar == 'D' && isMatchingPair(charStack, 'C')) {
                charStack.pop();
            } else {
                charStack.push(currentChar);
            }
        }

        return charStack.size();
    }

private:
    bool isMatchingPair(const stack<char>& charStack, char comparisonChar) {
        return !charStack.empty() && charStack.top() == comparisonChar;
    }
};
