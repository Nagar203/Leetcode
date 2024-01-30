#include <bits/stdc++.h>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto& ch : tokens) {
            if (isdigit(ch[0]) || (ch.size() > 1 && ch[0] == '-')) {
                st.push(stoi(ch));
            } else {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();

                if (ch == "+") {
                    st.push(num1 + num2);
                } else if (ch == "-") {
                    st.push(num1 - num2);
                } else if (ch == "*") {
                    st.push(num1 * num2);
                } else {
                    st.push(num1 / num2);
                }
            }
        }
        return st.top();
    }
};
