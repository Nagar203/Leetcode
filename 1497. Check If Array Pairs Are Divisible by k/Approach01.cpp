class Solution {
public:
    bool canArrange(std::vector<int>& numbers, int divisor) {
        std::vector<int> remainderCount(divisor);

        for (int number : numbers) {
            number %= divisor;
            ++remainderCount[number < 0 ? number + divisor : number];
        }

        if (remainderCount[0] % 2 != 0)
            return false;

        for (int i = 1; i <= divisor / 2; ++i) {
            if (remainderCount[i] != remainderCount[divisor - i])
                return false;
        }

        return true;
    }
};