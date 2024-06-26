#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        string result;

        // Split the string into words using a stringstream
        while (ss >> word) {
            result = word;
        }

        // Return the length of the last word
        return result.length();
    }
};