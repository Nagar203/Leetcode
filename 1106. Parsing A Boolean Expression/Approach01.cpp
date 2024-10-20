#include <string>
#include <vector>
#include <functional>
#include <algorithm>

class Solution {
public:
    bool parseBoolExpr(const std::string& expression) {
        return dfs(expression, 0, expression.size() - 1);
    }

private:
    bool dfs(const std::string& expression, int start, int end) {
        if (start == end)
            return expression[start] == 't';

        std::vector<bool> subExpressions;
        char operatorChar = '\0';
        int layer = 0;

        for (int i = start; i <= end; ++i) {
            char currentChar = expression[i];

            if (layer == 0 && (currentChar == '!' || currentChar == '&' || currentChar == '|')) {
                operatorChar = currentChar;
            } else if (currentChar == '(') {
                layer++;
                if (layer == 1) {
                    leftStart = i + 1;
                }
            } else if (currentChar == ')') {
                layer--;
                if (layer == 0) {
                    subExpressions.push_back(dfs(expression, leftStart, i - 1));
                }
            } else if (currentChar == ',' && layer == 1) {
                subExpressions.push_back(dfs(expression, leftStart, i - 1));
                leftStart = i + 1;
            }
        }

        if (operatorChar == '|')
            return std::any_of(subExpressions.begin(), subExpressions.end(), [](bool val) { return val; });
        if (operatorChar == '&')
            return std::all_of(subExpressions.begin(), subExpressions.end(), [](bool val) { return val; });
        if (operatorChar == '!')
            return !subExpressions[0];

        return false;
    }

    int leftStart = 0;
};
