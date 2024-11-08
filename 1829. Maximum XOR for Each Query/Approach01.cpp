#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        const int maxXorValue = (1 << maximumBit) - 1;  // Maximum value with all bits set to 1
        vector<int> result;
        int cumulativeXor = 0;

        for (const int num : nums) {
            cumulativeXor ^= num;
            result.push_back(cumulativeXor ^ maxXorValue);
        }

        // Reverse the result vector to match the required order
        reverse(result.begin(), result.end());
        return result;
    }
};