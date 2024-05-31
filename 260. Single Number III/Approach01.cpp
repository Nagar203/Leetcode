#include <vector>
#include <numeric>
#include <functional>

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        unsigned int xors = std::accumulate(nums.begin(), nums.end(), 0u, std::bit_xor<unsigned int>());
        unsigned int lowbit = xors & -xors;
        std::vector<int> result(2, 0);

        for (int num : nums) {
            if (num & lowbit) {
                result[0] ^= num;
            } else {
                result[1] ^= num;
            }
        }

        return result;
    }
};
