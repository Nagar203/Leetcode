class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string result;
        vector<int> charFrequency(26);

        for (const char c : s)
            ++charFrequency[c - 'a'];

        while (true) {
            const bool isAddingSingleChar = !result.empty() && shouldAddOne(result, charFrequency);
            const int largestCharIndex = getLargestChar(result, charFrequency);

            if (largestCharIndex == -1){
                break;
            }

            const int numRepeats = isAddingSingleChar ? 1 : min(charFrequency[largestCharIndex], repeatLimit);
            result += string(numRepeats, 'a' + largestCharIndex);
            charFrequency[largestCharIndex] -= numRepeats;
        }

        return result;
    }

private:
    bool shouldAddOne(const string& result, const vector<int>& charFrequency) {
        for (int i = 25; i >= 0; --i)
            if (charFrequency[i]){
                return result.back() == 'a' + i;
            }
        return false;
    }

    int getLargestChar(const string& result, const vector<int>& charFrequency) {
        for (int i = 25; i >= 0; --i)
            if (charFrequency[i] && (result.empty() || result.back() != 'a' + i)){
                return i;
            }
                
        return -1;
    }
};