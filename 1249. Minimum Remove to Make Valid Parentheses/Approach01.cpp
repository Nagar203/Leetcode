#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string minRemoveToMakeValid(string str) {
    stack<int> st;

    for (int i = 0; i < str.length(); ++i)
      if (str[i] == '(') {
        st.push(i);
      } else if (str[i] == ')') {
        if (st.empty())
          str[i] = '*';
        else
          st.pop();
      }

    while (!st.empty())
      str[st.top()] = '*', st.pop();

    str.erase(remove(str.begin(), str.end(), '*'), str.end());
    return str;
  }
};
