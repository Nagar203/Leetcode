#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool solve(string &word){
        int n = word.size();
        int i = 0, j = n-1;

        while(i<j){
            if(word[i] != word[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        
        for(string &word: words){
            if(solve(word)){
                return word;
            }
        }
        return "";
    }
};