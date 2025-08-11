class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    vector<int> productQueries(int number, vector<vector<int>>& queryRanges) {
        vector<int> powersOfTwo;
        while (number > 0) {
            int currentPower = number & -number;
            powersOfTwo.emplace_back(currentPower);
            number -= currentPower;
        }

        vector<int> results;
        for (auto& range : queryRanges) {
            int startIndex = range[0], endIndex = range[1];
            long long product = 1;
            for (int i = startIndex; i <= endIndex; ++i) {
                product = (product * powersOfTwo[i]) % MOD;
            }
            results.emplace_back(static_cast<int>(product));
        }
        return results;
    }
};
