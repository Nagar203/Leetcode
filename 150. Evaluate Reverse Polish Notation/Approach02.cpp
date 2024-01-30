#include <bits/stdc++.h>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_map<string, function<int(int, int)>> mp = {
            {"+", [](int a, int b){return a+b;}},
            {"-", [](int a, int b){return b-a;}},
            {"*", [](int a, int b){return (long)a*(long)b;}},
            {"/", [](int a, int b){return b/a;}}
        };

        for(string& token: tokens){
            if(token=="*" or token =="+" or token == "-" or token == "/"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();

                int result = mp[token](num1, num2);
                st.push(result);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};