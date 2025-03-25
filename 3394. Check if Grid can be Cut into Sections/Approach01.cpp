#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> xIntervals;
        vector<pair<int, int>> yIntervals;

        for (const vector<int>& rectangle : rectangles) {
            int startX = rectangle[0];
            int startY = rectangle[1];
            int endX = rectangle[2];
            int endY = rectangle[3];
            xIntervals.emplace_back(startX, endX);
            yIntervals.emplace_back(startY, endY);
        }

        return max(countMergedIntervals(xIntervals), countMergedIntervals(yIntervals)) >= 3;
    }

private:
    int countMergedIntervals(vector<pair<int, int>>& intervals) {
        int mergedCount = 0;
        int previousEnd = 0;

        ranges::sort(intervals);

        for (const auto& [start, end] : intervals) {
            if (start < previousEnd) {
                previousEnd = max(previousEnd, end);
            } else {
                previousEnd = end;
                ++mergedCount;
            }
        }

        return mergedCount;
    }
};
