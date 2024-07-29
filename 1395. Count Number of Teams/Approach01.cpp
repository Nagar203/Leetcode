#include <vector>

using namespace std;

class Solution {
public:
    int numTeams(vector<int>& ratings) {
        int totalTeams = 0;

        // Iterate through each soldier, considering them as the middle soldier in a team
        for (int middle = 1; middle < ratings.size() - 1; ++middle) {
            // Calculate the number of soldiers on the left with less/greater ratings than the middle soldier
            int leftLessCount = 0;
            int leftGreaterCount = 0;
            for (int left = 0; left < middle; ++left) {
                if (ratings[left] < ratings[middle]) {
                    ++leftLessCount;
                } else if (ratings[left] > ratings[middle]) {
                    ++leftGreaterCount;
                }
            }

            // Calculate the number of soldiers on the right with less/greater ratings than the middle soldier
            int rightLessCount = 0;
            int rightGreaterCount = 0;
            for (int right = middle + 1; right < ratings.size(); ++right) {
                if (ratings[right] < ratings[middle]) {
                    ++rightLessCount;
                } else if (ratings[right] > ratings[middle]) {
                    ++rightGreaterCount;
                }
            }

            // Calculate the number of valid teams using the current middle soldier
            totalTeams += leftLessCount * rightGreaterCount + leftGreaterCount * rightLessCount;
        }

        return totalTeams;
    }
};
