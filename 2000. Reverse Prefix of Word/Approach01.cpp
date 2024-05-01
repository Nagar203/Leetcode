#include <string>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        size_t index = word.find(ch);

        string rev_data = word.substr(0, index+1);
        string rem_data = word.substr(index+1);
        reverse(rev_data.begin(), rev_data.end());
        string result = rev_data + rem_data;
        return result;
    }
};
