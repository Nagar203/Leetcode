class Solution {
public:
    bool reorderedPowerOf2(int number) {
        int digitCountValue = getDigitCount(number);

        for (int bitShiftIndex = 0; bitShiftIndex < 30; ++bitShiftIndex)
            if (getDigitCount(1 << bitShiftIndex) == digitCountValue)
                return true;

        return false;
    }

private:
    int getDigitCount(int num) {
        int digitCountSum = 0;
        for (; num > 0; num /= 10)
            digitCountSum += pow(10, num % 10);
        return digitCountSum;
    }
};
