#include <string>

using namespace std;


class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int maxValue = 0;
        string result = "";

        for (int i = 0; i < n - 2; i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                int new_max = num[i] - '0';

                if (new_max >= maxValue) {
                    maxValue = new_max;
                    result = num.substr(i, 3);
                }
            }
        }
        return result;
    }
};