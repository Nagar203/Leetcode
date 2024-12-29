class Solution {
public:
    int targetLength;
    int wordLength;
    const int MOD = 1e9+7;
    int memo[1001][1001];
    
    int solve(int targetIndex, int columnIndex, vector<vector<long long>>& charFrequency, string &target) {
        if (targetIndex == targetLength) // Completed target formation
            return 1;
        if (columnIndex == wordLength) // Exhausted all columns
            return 0;
        if (memo[targetIndex][columnIndex] != -1) // Return memoized result
            return memo[targetIndex][columnIndex];
        
        // Option 1: Skip current column
        int skipColumn = solve(targetIndex, columnIndex + 1, charFrequency, target) % MOD;
        
        // Option 2: Use current column
        int useColumn = (charFrequency[target[targetIndex] - 'a'][columnIndex] * 
                         solve(targetIndex + 1, columnIndex + 1, charFrequency, target)) % MOD;
        
        return memo[targetIndex][columnIndex] = (skipColumn + useColumn) % MOD;
    }
    
    int numWays(vector<string>& words, string target) {
        wordLength = words[0].size();
        targetLength = target.length();
        
        // Build frequency table for each character at every column
        vector<vector<long long>> charFrequency(26, vector<long long>(wordLength, 0));
        for (int column = 0; column < wordLength; column++) {
            for (string &word : words) {
                charFrequency[word[column] - 'a'][column]++;
            }
        }
        
        // Initialize memoization table
        memset(memo, -1, sizeof(memo));
        return solve(0, 0, charFrequency, target);
    }
};