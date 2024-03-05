#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
       
        while (i < j and s[i]==s[j]) {            
            char current = s[i];

            while (i < j && s[i] == current) {
                i++;
            }

            while (i <= j && s[j] == current) {
                j--;
            }
        }
        return (j - i + 1);
    }
};