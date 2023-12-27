#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minCost(string colors, vector<int>& neededTime) {
    int result = 0;
    int max_needed_time = neededTime[0];

    for (int i = 1; i < colors.length(); ++i)
      if (colors[i] == colors[i - 1]) {
        result += min(max_needed_time, neededTime[i]);
        max_needed_time = max(max_needed_time, neededTime[i]);
      } else {        
        max_needed_time = neededTime[i];
      }

    return result;
  }
};