class Solution {
public:
    int minimumDeletions(string word, int k) {
        int minDeletions = INT_MAX;
        vector<int> charFrequency(26);

        for (char ch : word)
            ++charFrequency[ch - 'a'];

        for (int baseFreq : charFrequency) {
            int deletions = 0;
            for (int freq : charFrequency) {
                if (freq < baseFreq)
                    deletions += freq;
                else
                    deletions += max(0, freq - (baseFreq + k));
            }
            minDeletions = min(minDeletions, deletions);
        }

        return minDeletions;
    }
};
