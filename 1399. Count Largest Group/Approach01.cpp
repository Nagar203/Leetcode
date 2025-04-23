#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> groupSizes(36 + 1, 0);

        for (int number = 1; number <= n; ++number) {
            int sum = calculateDigitSum(number);
            ++groupSizes[sum];
        }

        int maxSize = *max_element(groupSizes.begin(), groupSizes.end());
        return count(groupSizes.begin(), groupSizes.end(), maxSize);
    }

private:
    int calculateDigitSum(int num) {
        int digitSum = 0;
        while (num > 0) {
            digitSum += num % 10;
            num /= 10;
        }
        return digitSum;
    }
};