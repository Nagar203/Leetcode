class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long result = 0;
        vector<long> count(n);

        for (const vector<int>& road : roads) {
            const int u = road[0];
            const int v = road[1];
            ++count[u];
            ++count[v];
        }

        ranges::sort(count);

        for (int i = 0; i < n; ++i)
            result += (i + 1) * count[i];

        return result;
    }
};