#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int numberOfBeams(vector<string>& bank) {
    int result = 0;
    int prevOnes = 0;

    for (const string& row : bank) {
      const int ones = ranges::count(row, '1');
      if (ones > 0) {
        result += prevOnes * ones;
        prevOnes = ones;
      }
    }

    return result;
  }
};