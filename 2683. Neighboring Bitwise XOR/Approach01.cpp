#include <vector>
#include <numeric>
#include <functional>

class Solution {
public:
    bool doesValidArrayExist(const std::vector<int>& derivedArray) {
        // Calculate the cumulative XOR of all elements in derivedArray
        int cumulativeXor = std::accumulate(derivedArray.begin(), derivedArray.end(), 0, std::bit_xor<int>());
        // A valid original array exists if the cumulative XOR is zero
        return cumulativeXor == 0;
    }
};