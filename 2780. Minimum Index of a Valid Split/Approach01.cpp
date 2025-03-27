#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int arraySize = nums.size();
        unordered_map<int, int> leftFrequency; 
        unordered_map<int, int> rightFrequency;

        for (int num : nums)
            ++rightFrequency[num];

        for (int i = 0; i < arraySize; ++i) {
            int leftCount = ++leftFrequency[nums[i]];
            int rightCount = --rightFrequency[nums[i]];
            
            if (leftCount * 2 > i + 1 && rightCount * 2 > arraySize - 1 - i)
                return i;
        }

        return -1;
    }
};
