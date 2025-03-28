#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string str1 = "";
        for (const string& word : word1) {
            str1 += word;
        }

        string str2 = "";
        for (const string& word : word2) {
            str2 += word;
        }

        return str1 == str2;
    }

};