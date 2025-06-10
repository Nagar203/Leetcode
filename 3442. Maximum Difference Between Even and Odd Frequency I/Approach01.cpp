class Solution {
public:
    int maxDifference(string s) {
        vector<int> charFrequency(26);
        int maxOddFrequency = 0;
        int minEvenFrequency = s.length();

        for (const char ch : s)
            ++charFrequency[ch - 'a'];

        for (const int frequency : charFrequency) {
            if (frequency == 0)
                continue;
            if (frequency % 2 == 0)
                minEvenFrequency = min(minEvenFrequency, frequency);
            else
                maxOddFrequency = max(maxOddFrequency, frequency);
        }

        return maxOddFrequency - minEvenFrequency;
    }
};
