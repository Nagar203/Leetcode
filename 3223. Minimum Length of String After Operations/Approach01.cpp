class Solution {
public:
    int minimumLength(string str) {
        unordered_map<char, int> charFrequency;
        int length = str.length();

        // Count the frequency of each character in the string
        for (char &ch : str) {
            ++charFrequency[ch];
        }

        // Adjust the length based on character frequencies
        for (auto [character, frequency] : charFrequency) {
            if (frequency % 2 == 0 && frequency > 2) {
                length = length - frequency + 2;
            } else if (frequency % 2 != 0 && frequency > 2) {
                length = length - frequency + 1;
            }
        }

        return length;
    }
};