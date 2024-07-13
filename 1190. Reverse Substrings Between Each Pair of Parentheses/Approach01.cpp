class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openParenthesisIndices;
        string result;

        for (const char c : s) {
            if (c == '(') {
                openParenthesisIndices.push(result.length());
            } else if (c == ')') {
                // Reverse the corresponding substring between ().
                const int startIndex = openParenthesisIndices.top();
                openParenthesisIndices.pop();
                reverse(result.begin() + startIndex, result.end());
            } else {
                result += c;
            }
        }

        return result;
    }
};