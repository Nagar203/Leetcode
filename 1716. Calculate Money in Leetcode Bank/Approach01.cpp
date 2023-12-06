#include <iostream>

using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int start = 1;
        int result = 0;

        while (n > 0) {
            for (int i = 0; i < 7 && n-- > 0; ++i){
                result += start + i;
            }
            start++;
        }
        return result;
    }
};