#include <stack>
#include <string>

class Solution {
public:
    std::string smallestNumber(std::string pattern) {
        std::string result;
        std::stack<char> numStack{{'1'}};

        for (const char direction : pattern) {
            char maxSoFar = numStack.top();
            
            if (direction == 'I') {
                // Pop all elements from the stack and add them to result
                while (!numStack.empty()) {
                    maxSoFar = std::max(maxSoFar, numStack.top());
                    result += numStack.top();
                    numStack.pop();
                }
            }
            
            numStack.push(maxSoFar + 1);
        }

        // Pop remaining elements in the stack
        while (!numStack.empty()) {
            result += numStack.top();
            numStack.pop();
        }

        return result;
    }
};