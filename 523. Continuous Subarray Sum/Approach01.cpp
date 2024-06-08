#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefix_sum = 0;
        unordered_map<int, int> prefix_sum_map;
        prefix_sum_map[0] = -1;

        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];
            int remainder = prefix_sum % k;

            if (prefix_sum_map.find(remainder) != prefix_sum_map.end()) {
                if (i - prefix_sum_map[remainder] > 1) {
                    return true;
                }
            } else {
                prefix_sum_map[remainder] = i;
            }
        }

        return false;
    }
};