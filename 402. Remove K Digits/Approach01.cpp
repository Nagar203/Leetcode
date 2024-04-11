#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        int n = num.length();
        std::vector<char> result;

        for (int i = 0; i < n; ++i) {
            while (!result.empty() && result.back() > num[i] && k > 0) {
                result.pop_back();
                k--;
            }
            if (!result.empty() || num[i] != '0') {
                result.push_back(num[i]);
            }
        }
        
        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }
        
        if (result.empty()) {
            return "0";
        }
        
        return std::string(result.begin(), result.end());
    }
};
