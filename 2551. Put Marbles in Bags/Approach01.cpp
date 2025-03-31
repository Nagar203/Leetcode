class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> splitCosts;
        long minScore = 0;
        long maxScore = 0;

        for (int i = 0; i + 1 < weights.size(); ++i)
            splitCosts.push_back(weights[i] + weights[i + 1]);

        ranges::sort(splitCosts);

        for (int i = 0; i < k - 1; ++i) {
            minScore += splitCosts[i];
            maxScore += splitCosts[splitCosts.size() - 1 - i];
        }

        return maxScore - minScore;
    }
};