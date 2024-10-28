#include <unordered_set>
#include <vector>

class Solution {
public:
    int longestSquareStreak(vector<int>& numbers) {
        // Remove duplicates and sort in descending order
        numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());
        ranges::sort(numbers, greater<>());

        const int maxNumber = ranges::max(numbers);
        // dp[i] represents the longest square streak starting with i
        vector<int> dp(maxNumber + 1);

        for (const int number : numbers) {
            dp[number] = 1;
            const long squaredNumber = static_cast<long>(number) * number;
            if (squaredNumber <= maxNumber)
                dp[number] += dp[squaredNumber];
        }

        const int result = ranges::max(dp);
        return result < 2 ? -1 : result;
    }
};