#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int result = 0;
        int score = 0;
        sort(tokens.begin(), tokens.end());
        deque<int> q(tokens.begin(), tokens.end());

        while (!q.empty() && (power >= q.front() || score)) {
            while (!q.empty() && power >= q.front()) {
                power -= q.front();
                q.pop_front();
                score++;
            }
            result = max(result, score);
            if (!q.empty() && score) {
                power += q.back();
                q.pop_back();
                score--;
            }
        }

        return result;
    }
};