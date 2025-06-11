class Solution {
public:
    int maxDifference(string s, int k) {
        int maxDifferenceValue = INT_MIN;

        for (const auto& [charA, charB] : getPermutations()) {
            vector<vector<int>> minDifferenceByParity(2, vector<int>(2, INT_MAX / 2));
            vector<int> prefixCountA{0};
            vector<int> prefixCountB{0};

            for (int left = 0, right = 0; right < static_cast<int>(s.length()); ++right) {
                prefixCountA.push_back(prefixCountA.back() + (s[right] == charA));
                prefixCountB.push_back(prefixCountB.back() + (s[right] == charB));

                while (right - left + 1 >= k && prefixCountA[left] < prefixCountA.back() && prefixCountB[left] < prefixCountB.back()) {
                    int& currentMin = minDifferenceByParity[prefixCountA[left] % 2][prefixCountB[left] % 2];
                    currentMin = min(currentMin, prefixCountA[left] - prefixCountB[left]);
                    ++left;
                }

                int currentDifference = (prefixCountA.back() - prefixCountB.back()) - minDifferenceByParity[1 - (prefixCountA.back() % 2)][prefixCountB.back() % 2];

                maxDifferenceValue = max(maxDifferenceValue, currentDifference);
            }
        }
        return maxDifferenceValue;
    }

private:
    vector<pair<char, char>> getPermutations() {
        vector<pair<char, char>> permutations;
        for (const char charA : "01234")
            for (const char charB : "01234")
                if (charA != charB)
                    permutations.emplace_back(charA, charB);
        return permutations;
    }
};
