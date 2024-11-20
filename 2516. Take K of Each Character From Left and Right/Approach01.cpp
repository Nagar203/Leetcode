#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
  int takeCharacters(string inputString, int minFrequency) {
    const int stringLength = inputString.length();
    int minDeletions = stringLength;
    vector<int> characterCount(3, 0);

    // Count the frequency of each character
    for (const char character : inputString)
      ++characterCount[character - 'a'];

    // If any character's frequency is less than minFrequency, return -1
    if (characterCount[0] < minFrequency || characterCount[1] < minFrequency || characterCount[2] < minFrequency)
      return -1;

    // Sliding window to find the minimum substring length
    for (int leftIndex = 0, rightIndex = 0; rightIndex < stringLength; ++rightIndex) {
      --characterCount[inputString[rightIndex] - 'a'];
      while (characterCount[inputString[rightIndex] - 'a'] < minFrequency)
        ++characterCount[inputString[leftIndex++] - 'a'];
      minDeletions = min(minDeletions, stringLength - (rightIndex - leftIndex + 1));
    }

    return minDeletions;
  }
};