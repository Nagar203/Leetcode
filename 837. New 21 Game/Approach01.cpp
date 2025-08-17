class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k - 1 + maxPts)
            return 1.0;

        double probabilitySum = 0.0;
        vector<double> dp(n + 1);  // dp[i] = probability of having exactly i points
        dp[0] = 1.0;
        double slidingWindowSum = dp[0];  // rolling sum for probabilities

        for (int points = 1; points <= n; ++points) {
            dp[points] = slidingWindowSum / maxPts;

            if (points < k)
                slidingWindowSum += dp[points];
            else
                probabilitySum += dp[points];

            if (points - maxPts >= 0)
                slidingWindowSum -= dp[points - maxPts];
        }

        return probabilitySum;
    }
};
