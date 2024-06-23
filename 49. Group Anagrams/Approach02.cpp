#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> result(n, vector<int>(26, 0));
        vector<bool> visited(n, false);
        vector<vector<string>> final_result;

        // Calculate frequency arrays for each string
        for (int i = 0; i < n; ++i) {
            for (char ch : strs[i]) {
                result[i][ch - 'a']++;
            }
        }

        // Group anagrams
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<string> temp_list;
                for (int j = i; j < n; ++j) {
                    if (result[i] == result[j] && !visited[j]) {
                        temp_list.push_back(strs[j]);
                        visited[j] = true;
                    }
                }
                final_result.push_back(temp_list);
            }
        }

        return final_result;
    }
};
