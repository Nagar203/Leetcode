class Solution {
public:
    double soupServings(int totalSoup) {
        return totalSoup >= 4800 ? 1.0 : dfs((totalSoup + 24) / 25, (totalSoup + 24) / 25);
    }

private:
    vector<vector<double>> memo = vector<vector<double>>(4800 / 25, vector<double>(4800 / 25));

    double dfs(int soupA, int soupB) {
        if (soupA <= 0 && soupB <= 0)
            return 0.5;
        if (soupA <= 0)
            return 1.0;
        if (soupB <= 0)
            return 0.0;
        if (memo[soupA][soupB] > 0)
            return memo[soupA][soupB];
        return memo[soupA][soupB] = 0.25 * (
            dfs(soupA - 4, soupB) +
            dfs(soupA - 3, soupB - 1) +
            dfs(soupA - 2, soupB - 2) +
            dfs(soupA - 1, soupB - 3)
        );
    }
};
