#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool canBeValid(string brackets, string locked) {
    // If the length of the string is odd, it's impossible to make valid parentheses
    if (brackets.length() % 2 == 1)
      return false;

    // Check both directions: left-to-right and right-to-left
    const bool leftToRightIsValid = validateBrackets(brackets, locked, true);
    reverse(brackets.begin(), brackets.end());
    reverse(locked.begin(), locked.end());
    const bool rightToLeftIsValid = validateBrackets(brackets, locked, false);

    return leftToRightIsValid && rightToLeftIsValid;
  }

private:
  bool validateBrackets(const string& brackets, const string& locked, bool isForward) {
    int changeableCount = 0; // Count of brackets that can be changed
    int openCount = 0;       // Count of open brackets
    int closeCount = 0;      // Count of close brackets

    for (int i = 0; i < brackets.length(); ++i) {
      const char currentBracket = brackets[i];
      const char isLocked = locked[i];

      if (isLocked == '0') {
        ++changeableCount; // Bracket can be changed
      } else if (currentBracket == '(') {
        ++openCount; // Count open brackets
      } else { // currentBracket == ')'
        ++closeCount; // Count close brackets
      }

      // Check if it's valid based on the current counts
      if (isForward && changeableCount + openCount - closeCount < 0)
        return false;
      if (!isForward && changeableCount + closeCount - openCount < 0)
        return false;
    }

    return true;
  }
};
