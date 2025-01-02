#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowelsSet = {'a', 'e', 'i', 'o', 'u'};
        vector<int> prefixSumArray(words.size() + 1, 0);

        // Compute prefix sums where prefixSumArray[i] indicates the count of valid words up to index i-1
        for (int index = 0; index < words.size(); ++index) {
            const string& word = words[index];
            prefixSumArray[index + 1] = prefixSumArray[index] + (vowelsSet.count(word.front()) && vowelsSet.count(word.back()) ? 1 : 0);
        }

        // Process each query and calculate the count of valid words within the range
        vector<int> resultList;
        for (const auto& query : queries) {
            int queryStart = query[0];
            int queryEnd = query[1];
            resultList.push_back(prefixSumArray[queryEnd + 1] - prefixSumArray[queryStart]);
        }

        return resultList;
    }
};