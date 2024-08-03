#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Helper function to get the frequency dictionary of elements in a vector
    unordered_map<int, int> get_dict(const vector<int>& data) {
        unordered_map<int, int> data_dict;
        for (int t : data) {
            // If the element t is not in the dictionary, initialize its count to 1
            // Otherwise, increment its count by 1
            if (data_dict.find(t) == data_dict.end()) {
                data_dict[t] = 1;
            } else {
                data_dict[t]++;
            }
        }
        return data_dict;
    }

    // Function to check if target can be made equal to arr by shuffling
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // Get frequency dictionaries for both target and arr
        unordered_map<int, int> target_dict = get_dict(target);
        unordered_map<int, int> arr_dict = get_dict(arr);

        // Iterate through the frequency dictionary of target
        for (const auto& pair : target_dict) {
            int key = pair.first;
            int val = pair.second;
            // If key is not present in arr or its count does not match in both dictionaries, return false
            if (arr_dict.find(key) == arr_dict.end() || arr_dict[key] != val) {
                return false;
            }
        }
        
        // If all keys match with their counts, return true
        return true;
    }
};
