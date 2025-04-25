#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long totalSubarrays = 0;
        int prefixModCount = 0;
        unordered_map<int, int> prefixFrequency{{0, 1}};

        for (const int num : nums) {
            if (num % modulo == k)
                prefixModCount = (prefixModCount + 1) % modulo;

            int target = (prefixModCount - k + modulo) % modulo;
            totalSubarrays += prefixFrequency[target];
            ++prefixFrequency[prefixModCount];
        }

        return totalSubarrays;
    }
};