#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& numbers) {
        constexpr int maxDigitSum = 81; // Maximum possible digit sum (9*9)
        int maxPairSum = -1;
        vector<vector<int>> digitSumGroups(maxDigitSum + 1);

        for (const int number : numbers)
            digitSumGroups[calculateDigitSum(number)].push_back(number);

        for (vector<int>& group : digitSumGroups) {
            if (group.size() < 2)
                continue;
            ranges::sort(group, greater<>());
            maxPairSum = max(maxPairSum, group[0] + group[1]);
        }

        return maxPairSum;
    }

private:
    int calculateDigitSum(int number) {
        int digitSum = 0;
        while (number > 0) {
            digitSum += number % 10;
            number /= 10;
        }
        return digitSum;
    }
};
