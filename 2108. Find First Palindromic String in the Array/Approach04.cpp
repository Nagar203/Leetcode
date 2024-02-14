#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    string firstPalindrome(vector<string>& words) {
        
        for(string &word: words){
            string temp = word;

            if(word == string(word.rbegin(), word.rend())){
                return word;
            }
        }
        return "";
    }
};