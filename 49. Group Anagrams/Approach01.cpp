#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            groups[sorted_str].push_back(str);
        }

        vector<vector<string>> result;
        for (const auto& pair : groups) {
            result.push_back(pair.second);
        }

        return result;
    }
};
