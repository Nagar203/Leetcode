class Solution {
public:
    int MOD = 1000000007;
    vector<int> memo;

    int solve(int low, int high, int zero, int one, int currentLength) {
        if (currentLength > high) {
            return 0;
        }

        if(memo[currentLength] != -1){
            return memo[currentLength];
        }

        int total = 0;

        // Base case: Valid string length
        if (currentLength >= low && currentLength <= high) {
            total = 1;
        }

        // Recursive case: Add zeros and ones
        int left = solve(low, high, zero, one, currentLength + zero);
        int right = solve(low, high, zero, one, currentLength + one);

        total = (total + left + right) % MOD;
        memo[currentLength] = total;
        return total;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        memo.assign(high+1, -1);
        return solve(low, high, zero, one, 0);
    }
};