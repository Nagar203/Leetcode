#include <string>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  bool canConstruct(string inputString, int numPalindromes) {
    if (inputString.length() < numPalindromes) {
      return false;
    }

    unordered_set<char> oddFrequencyTracker;

    for (char character : inputString) {
      if (oddFrequencyTracker.find(character) != oddFrequencyTracker.end()) {
        oddFrequencyTracker.erase(character);
      } else {
        oddFrequencyTracker.insert(character);
      }
    }

    return oddFrequencyTracker.size() <= numPalindromes;
  }
};
