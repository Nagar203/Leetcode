#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> numberToIndices;

        for (int index = 0; index < nums.size(); ++index) {
            int number = nums[index];
            numberToIndices[number].push_back(index);
        }

        int validPairCount = 0;
        for (const auto& [number, indices] : numberToIndices) {
            int indexCount = indices.size();
            for (int i = 0; i < indexCount - 1; ++i) {
                for (int j = i + 1; j < indexCount; ++j) {
                    if ((indices[i] * indices[j]) % k == 0) {
                        ++validPairCount;
                    }
                }
            }
        }

        return validPairCount;
    }
};