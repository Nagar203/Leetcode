class Solution {
 public:
  int maximumLength(string s) {
    const int stringLength = s.length();
    int maxLength = -1;
    int currentLength = 0;
    char previousChar = '@';
    // counts[charIndex][repetition] := the frequency of ('a' + charIndex) repeating `repetition` times
    vector<vector<int>> charFrequency(26, vector<int>(stringLength + 1));

    for (const char currentChar : s) {
      if (currentChar == previousChar) {
        ++charFrequency[currentChar - 'a'][++currentLength];
      } else {
        currentLength = 1;
        ++charFrequency[currentChar - 'a'][currentLength];
        previousChar = currentChar;
      }
    }

    for (const vector<int>& frequency : charFrequency) {
      maxLength = max(maxLength, getMaxFreq(frequency, stringLength));
    }

    return maxLength;
  }

 private:
  // Returns the maximum frequency that occurs more than three times.
  int getMaxFreq(const vector<int>& frequency, int maxFrequency) {
    int occurrences = 0;
    for (int freq = maxFrequency; freq >= 1; --freq) {
      occurrences += frequency[freq];
      if (occurrences >= 3)
        return freq;
    }
    return -1;
  }
};