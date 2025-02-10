class Solution {
  public:
    string clearDigits(string inputStr) {
        vector<char> resultStack;
        
        for (char currentChar : inputStr) {
            if (!resultStack.empty() && isalpha(resultStack.back()) && isdigit(currentChar)) {
                resultStack.pop_back();
            } else if (!resultStack.empty() && isdigit(resultStack.back()) && isalpha(currentChar)) {
                resultStack.pop_back();
            } else {
                resultStack.push_back(currentChar);
            }
        }

        return string(resultStack.begin(), resultStack.end());
    }
};
