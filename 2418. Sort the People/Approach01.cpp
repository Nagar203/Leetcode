#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        std::unordered_map<int, std::string> data;
        int n = names.size();
        std::vector<std::string> result;

        for (int i = 0; i < n; ++i) {
            data[heights[i]] = names[i];
        }

        std::sort(heights.begin(), heights.end(), std::greater<int>());

        for (int i = 0; i < n; ++i) {
            result.push_back(data[heights[i]]);
        }

        return result;
    }
};
