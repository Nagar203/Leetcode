#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        const long totalSum = accumulate(nums.begin(), nums.end(), 0L);
        const int remainder = totalSum % p;
        if (remainder == 0)
            return 0;

        unordered_map<int, int> prefixToIndex{{0, -1}};
        int minLength = nums.size();
        int prefixSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            prefixSum %= p;
            const int target = (prefixSum - remainder + p) % p;
            if (const auto it = prefixToIndex.find(target);
                it != prefixToIndex.cend())
                minLength = min(minLength, i - it->second);
            prefixToIndex[prefixSum] = i;
        }

        return minLength == nums.size() ? -1 : minLength;
    }
};