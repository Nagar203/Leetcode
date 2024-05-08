#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sorted_score = score;
        sort(sorted_score.begin(), sorted_score.end(), greater<int>());

        unordered_map<int, int> rank_map;
        vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<string> result;

        for (int i = 0; i < sorted_score.size(); ++i) {
            rank_map[sorted_score[i]] = i + 1;
        }

        for (int i = 0; i < score.size(); ++i) {
            int rank = rank_map[score[i]];
            if (rank <= 3) {
                result.push_back(medals[rank - 1]);
            } else {
                result.push_back(to_string(rank));
            }
        }

        return result;
    }
};