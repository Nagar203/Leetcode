#include <vector>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int totalRabbits = 0;
        vector<int> answerFrequency(1000);

        for (const int reportedSameColorCount : answers) {
            if (answerFrequency[reportedSameColorCount] % (reportedSameColorCount + 1) ==0){
                totalRabbits += reportedSameColorCount + 1;
            }                
            ++answerFrequency[reportedSameColorCount];
        }
        return totalRabbits;
    }
};