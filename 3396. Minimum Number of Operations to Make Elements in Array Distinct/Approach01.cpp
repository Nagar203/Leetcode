#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int totalElements = nums.size(); 
        unordered_set<int> uniqueCheck(nums.begin(), nums.end());
        if (uniqueCheck.size() == totalElements)
            return 0;

        int operationsCount = 0;
        int currentIndex = 0;

        while (currentIndex < totalElements) {
            unordered_set<int> subarraySet;
            bool isUnique = true;

            for (int i = currentIndex; i < totalElements; ++i) {
                if (subarraySet.count(nums[i])) {
                    isUnique = false;
                    break;
                }
                subarraySet.insert(nums[i]);
            }

            if (isUnique)
                break;

            operationsCount++;
            currentIndex += 3;
        }

        return operationsCount;
    }
};