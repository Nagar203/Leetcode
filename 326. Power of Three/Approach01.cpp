class Solution {
public:
    bool isPowerOfThree(int number) {
        if (number <= 0) {
            return false;
        }
        while (number) {
            if (number == 1) {
                return true;
            }
            if (number % 3 != 0) {
                return false;
            }
            number /= 3;
        }
        return true;
    }
};
