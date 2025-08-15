class Solution {
public:
    bool isPowerOfFour(int number) {
        while (number) {
            if (number == 1) {
                return true;
            }
            if (number % 4 != 0) {
                return false;
            }
            number /= 4;
        }
        return false;
    }
};