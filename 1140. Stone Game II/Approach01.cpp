#include <algorithm>
#include <vector>

class Solution {
public:
    int stoneGameII(std::vector<int>& piles) {
        const int numberOfPiles = piles.size();
        std::vector<std::vector<int>> memo(numberOfPiles, std::vector<int>(numberOfPiles));
        
        // Compute the suffix sum for each index, which represents the sum of all elements from that index to the end.
        std::vector<int> suffixSum = piles; // suffixSum[i] := sum(piles[i..n))
        for (int i = numberOfPiles - 2; i >= 0; --i) {
            suffixSum[i] += suffixSum[i + 1];
        }

        // Start the recursion to find the maximum stones Alice can collect
        return getMaxStones(suffixSum, 0, 1, memo);
    }

private:
    // This function recursively determines the maximum number of stones Alice can collect
    // starting from the current index with the given value of M.
    int getMaxStones(const std::vector<int>& suffixSum, int currentIndex,
                     int maxM, std::vector<std::vector<int>>& memo) {
        // If the current player can take all remaining piles, return the sum of those piles
        if (currentIndex + 2 * maxM >= memo.size()) {
            return suffixSum[currentIndex];
        }

        // If this state has already been computed, return the stored result to avoid recomputation
        if (memo[currentIndex][maxM] > 0) {
            return memo[currentIndex][maxM];
        }

        // Calculate the minimum number of stones the opponent can leave to Alice
        int minimumOpponentStones = suffixSum[currentIndex];

        // Iterate over all possible choices for X, where X ranges from 1 to 2 * M
        // and determine the best worst-case scenario
        for (int X = 1; X <= 2 * maxM; ++X) {
            minimumOpponentStones = std::min(minimumOpponentStones, getMaxStones(suffixSum, currentIndex + X, std::max(maxM, X), memo));
        }

        // Store the result in memo and return the maximum stones Alice can collect from this point
        return memo[currentIndex][maxM] = suffixSum[currentIndex] - minimumOpponentStones;
    }
};