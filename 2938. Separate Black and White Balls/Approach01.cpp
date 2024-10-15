class Solution {
public:
    long long minimumSteps(string binaryString) {
        long totalSteps = 0;
        int countOnes = 0;

        for (const char currentChar : binaryString) {
            if (currentChar == '1') {
                ++countOnes;
            } else { // Move 1s to the front of the current '0'.
                totalSteps += countOnes;
            }
        }

        return totalSteps;
    }
};