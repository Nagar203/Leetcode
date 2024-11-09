class Solution {
public:
    long long minEnd(int numBits, int inputNum) {
        // Calculate maximum bits needed based on the inputs
        const int maxBits = log2(numBits) + log2(inputNum) + 2;
        const long targetValue = numBits - 1;
        long resultNum = inputNum;
        int bitIndex = 0;

        // Iterate through each bit up to maxBits
        for (int i = 0; i < maxBits; ++i) {
            // Check if the current bit of resultNum is 0
            if ((resultNum >> i & 1) == 0) {
                // If the corresponding bit in targetValue is 1, set it in resultNum
                if (targetValue >> bitIndex & 1)
                    resultNum |= 1L << i;
                ++bitIndex;
            }
        }

        return resultNum;
    }
};