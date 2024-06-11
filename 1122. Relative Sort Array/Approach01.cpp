#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        vector<int> result;

        for (int num : arr1) {
            mp[num]++;
        }

        for (int num : arr2) {
            if (mp.count(num)) {
                result.insert(result.end(), mp[num], num);
                mp.erase(num);
            }
        }

        vector<int> remaining;
        for (auto& pair : mp) {
            remaining.insert(remaining.end(), pair.second, pair.first);
        }
        
        sort(remaining.begin(), remaining.end());
        result.insert(result.end(), remaining.begin(), remaining.end());
        
        return result;
    }
};
