class Solution {
public:
    int maximumGain(string s, int x, int y) {
        return x > y ? calculateGain(s, "ab", x, "ba", y) : calculateGain(s, "ba", y, "ab", x);
    }

private:
    int calculateGain(const string& s, const string& firstPair, int firstPoints, const string& secondPair, int secondPoints) {
        int totalPoints = 0;
        vector<char> firstStack;
        vector<char> secondStack;

        for (const char c : s) {
            if (!firstStack.empty() && firstStack.back() == firstPair[0] && c == firstPair[1]) {
                firstStack.pop_back();
                totalPoints += firstPoints;
            } else {
                firstStack.push_back(c);
            }
        }

        for (const char c : firstStack) {
            if (!secondStack.empty() && secondStack.back() == secondPair[0] && c == secondPair[1]) {
                secondStack.pop_back();
                totalPoints += secondPoints;
            } else {
                secondStack.push_back(c);
            }
        }

        return totalPoints;
    }
};
