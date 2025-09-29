class Solution {
public:
    int minScoreTriangulation(vector<int>& vertexValues) {
        const int n = vertexValues.size();
        vector<vector<int>> minScore(n, vector<int>(n));

        for (int endIndex = 2; endIndex < n; ++endIndex) {
            for (int startIndex = endIndex - 2; startIndex >= 0; --startIndex) {
                minScore[startIndex][endIndex] = INT_MAX;
                for (int middleIndex = startIndex + 1; middleIndex < endIndex; ++middleIndex) {
                    minScore[startIndex][endIndex] = min(
                        minScore[startIndex][endIndex],
                        minScore[startIndex][middleIndex] +
                        vertexValues[startIndex] * vertexValues[middleIndex] * vertexValues[endIndex] +
                        minScore[middleIndex][endIndex]
                    );
                }
            }
        }

        return minScore[0][n - 1];
    }
};
