#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> data = score;
        sort(data.begin(), data.end(), greater<int>());
        
        unordered_map<int, int> mp;
        int size = data.size();
        int j = 0;
        vector<string> result;

        for (int i = 0; i < size; ++i) {
            mp[data[j]] = i + 1;
            ++j;
        }

        for (int d : score) {
            int val = mp[d];
            if (val == 1) {
                result.push_back("Gold Medal");
            } else if (val == 2) {
                result.push_back("Silver Medal");
            } else if (val == 3) {
                result.push_back("Bronze Medal");
            } else {
                result.push_back(to_string(val));
            }
        }

        return result;
    }
};
