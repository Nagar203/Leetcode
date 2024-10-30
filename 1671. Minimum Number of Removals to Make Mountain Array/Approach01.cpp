#include <unordered_set>
#include <vector>

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        const vector<int> leftLIS = calculateLIS(nums);
        const vector<int> rightLIS = reverseVector(calculateLIS(reverseVector(nums)));
        int maxMountainSequence = 0;

        for (int i = 0; i < nums.size(); ++i)
            if (leftLIS[i] > 1 && rightLIS[i] > 1)
                maxMountainSequence = max(maxMountainSequence, leftLIS[i] + rightLIS[i] - 1);

        return nums.size() - maxMountainSequence;
    }

private:
    // Helper function for Longest Increasing Subsequence
    vector<int> calculateLIS(vector<int> nums) {
        vector<int> tails;
        vector<int> lisLengths;
        for (const int num : nums) {
            if (tails.empty() || num > tails.back())
                tails.push_back(num);
            else
                tails[findFirstGreaterOrEqual(tails, num)] = num;
            lisLengths.push_back(tails.size());
        }
        return lisLengths;
    }

    int findFirstGreaterOrEqual(const vector<int>& sequence, int target) {
        return lower_bound(sequence.begin(), sequence.end(), target) -
               sequence.begin();
    }

    vector<int> reverseVector(const vector<int>& nums) {
        return {nums.rbegin(), nums.rend()};
    }
};