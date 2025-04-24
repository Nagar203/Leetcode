#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        // Maximum possible value in nums
        constexpr int kMaxValue = 2000;  
        // Total number of distinct elements in the entire array
        int totalDistinctCount = unordered_set<int>(nums.begin(), nums.end()).size();
        
        int completeCount = 0;
        int windowDistinct = 0;
        vector<int> frequency(kMaxValue + 1, 0);
        int left = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            int currentNum = nums[right];
            if (++frequency[currentNum] == 1)
                ++windowDistinct;  // new distinct enters window
            
            // Shrink window from left until it no longer contains all distinct
            while (windowDistinct == totalDistinctCount) {
                int leftNum = nums[left++];
                if (--frequency[leftNum] == 0)
                    --windowDistinct;
            }
            
            // All subarrays ending at right and starting before 'left' are complete
            completeCount += left;
        }
        
        return completeCount;
    }
};