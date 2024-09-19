#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class Solution {
 public:
    std::vector<int> diffWaysToCompute(const std::string& expression) {
        return computeWays(expression, {});
    }

 private:
    std::vector<int> computeWays(const std::string& expression, std::unordered_map<std::string, std::vector<int>>&& memoization) {
        if (const auto it = memoization.find(expression); it != memoization.cend()){
            return it->second;
        }

    std::vector<int> results;

    for (int index = 0; index < expression.length(); ++index)
        if (ispunct(expression[index]))
            for (const int leftPart : computeWays(expression.substr(0, index), std::move(memoization)))
                for (const int rightPart : computeWays(expression.substr(index + 1), std::move(memoization)))
                    if (expression[index] == '+')
                        results.push_back(leftPart + rightPart);
                    else if (expression[index] == '-')
                        results.push_back(leftPart - rightPart);
                    else
                        results.push_back(leftPart * rightPart);

    return memoization[expression] = (results.empty() ? std::vector<int>{std::stoi(expression)} : results);
    }
};