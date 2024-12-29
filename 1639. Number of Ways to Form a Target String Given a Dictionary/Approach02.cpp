class Solution {
public:
    const int MOD = 1e9+7;
    int numWays(vector<string>& words, string target) {
        int wordLength = words[0].size();
        int targetLength = target.length();
        
        // Build frequency table for each character at every column
        vector<vector<long long>> charFrequency(26, vector<long long>(wordLength, 0));
        for (int column = 0; column < wordLength; column++) {
            for (string &word : words) {
                charFrequency[word[column] - 'a'][column]++;
            }
        }
        
        // dp[targetLength][columnLength]: Total ways to form target of length targetLength using columnLength columns
        vector<vector<long long>> dp(targetLength + 1, vector<long long>(wordLength + 1, 0));
        dp[0][0] = 1; // Base case: 1 way to form empty target
        
        for (int targetIndex = 0; targetIndex <= targetLength; targetIndex++) {
            for (int columnIndex = 0; columnIndex <= wordLength; columnIndex++) {
                // Skip current column
                if (columnIndex < wordLength)
                    dp[targetIndex][columnIndex + 1] = (dp[targetIndex][columnIndex + 1] + dp[targetIndex][columnIndex]) % MOD;
                
                // Use current column
                if (targetIndex < targetLength && columnIndex < wordLength) {
                    dp[targetIndex + 1][columnIndex + 1] = (dp[targetIndex + 1][columnIndex + 1] + 
                        charFrequency[target[targetIndex] - 'a'][columnIndex] * dp[targetIndex][columnIndex]) % MOD;
                }
            }
        }
        return dp[targetLength][wordLength];
    }
};