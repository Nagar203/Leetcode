#include <string>

using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        string result;

        for (int i = 2; i < num.length(); ++i)
        if (num[i - 2] == num[i - 1] && num[i - 1] == num[i])
            result = max(result, num.substr(i - 2, 3));

        return result;
    }
};