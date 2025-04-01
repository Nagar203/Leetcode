#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int numQuestions = questions.size();
        vector<long> maxPoints(numQuestions + 1);

        for (int currentIndex = numQuestions - 1; currentIndex >= 0; --currentIndex) {
            int currentPoints = questions[currentIndex][0];
            int brainpower = questions[currentIndex][1];
            int nextQuestionIndex = currentIndex + brainpower + 1;
            long nextQuestionPoints = nextQuestionIndex < numQuestions ? maxPoints[nextQuestionIndex] : 0;
            maxPoints[currentIndex] = max(currentPoints + nextQuestionPoints, maxPoints[currentIndex + 1]);
        }
        
        return maxPoints[0]; 
    }
};