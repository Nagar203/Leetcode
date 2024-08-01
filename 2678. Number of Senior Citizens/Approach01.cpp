#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniorCount = 0;
        for (const string& detail : details) {
            // Extract the age from the last 4th and 3rd characters and convert to integer
            int age = stoi(detail.substr(detail.size() - 4, 2));
            if (age > 60) {
                seniorCount += 1;
            }
        }
        return seniorCount;
    }
};
