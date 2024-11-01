#include <unordered_set>
#include <vector>

class Solution {
 public:
  string makeFancyString(string inputString) {
    string resultString;
    
    for (const char currentChar : inputString) {
      // Append the character if the last two characters are not the same as the current one
      if (resultString.length() < 2 || resultString.back() != currentChar || resultString[resultString.size() - 2] != currentChar) {
        resultString.push_back(currentChar);
      }
    }
    
    return resultString;
  }
};