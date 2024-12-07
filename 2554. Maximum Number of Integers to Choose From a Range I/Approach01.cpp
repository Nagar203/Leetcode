class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> bannedSet(begin(banned), end(banned));
        int validCount = 0;
        int currentSum = 0;

        for (int currentNum = 1; currentNum <= n; currentNum++) {
            if (bannedSet.count(currentNum)) {
                continue;
            }

            if (currentSum + currentNum <= maxSum) {
                validCount++;
                currentSum += currentNum;
            } else {
                break;
            }
        }

        return validCount;
    }
};