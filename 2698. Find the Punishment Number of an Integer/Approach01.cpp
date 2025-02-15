#include <string>
using namespace std;

class Solution {
public:
    bool canPartition(const string& squareStr, int target, int index, int currentSum) {
        if (index == squareStr.length())
            return currentSum == target;

        int tempSum = 0;
        for (int j = index; j < squareStr.length(); j++) {
            tempSum = tempSum * 10 + (squareStr[j] - '0');

            if (tempSum + currentSum > target)
                break;

            if (canPartition(squareStr, target, j + 1, currentSum + tempSum))
                return true;
        }

        return false;
    }

    int punishmentNumber(int n) {
        int totalSum = 0;

        for (int i = 1; i <= n; i++) {
            string squareStr = to_string(i * i);
            if (canPartition(squareStr, i, 0, 0))
                totalSum += i * i;
        }

        return totalSum;
    }
};