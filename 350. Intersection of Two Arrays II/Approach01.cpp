#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int scoreOfString(string s) {
    int result = 0;

    for (int i = 1; i < s.length(); ++i){
        result += abs(s[i] - s[i - 1]);
    }

    return result;
  }
};