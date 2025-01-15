class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBitsInNum2 = __builtin_popcount(num2);
        int minimizedResult = 0;

        // Set bits in minimizedResult matching bits from num1, starting from MSB
        for (int bit = 31; bit >= 0; --bit) {
            if (setBitsInNum2 == 0) break;
            if (num1 & (1 << bit)) {
                minimizedResult |= (1 << bit);
                --setBitsInNum2;
            }
        }

        // Set remaining bits from LSB to minimize the XOR value
        for (int bit = 0; bit < 32; ++bit) {
            if (setBitsInNum2 == 0) break;
            if (!(minimizedResult & (1 << bit))) {
                minimizedResult |= (1 << bit);
                --setBitsInNum2;
            }
        }

        return minimizedResult;
    }
};