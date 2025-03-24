#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countDays(int totalDays, vector<vector<int>>& meetings) {
        if (meetings.empty()) 
            return totalDays;
  
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> mergedMeetings;
        
        for (const vector<int>& meeting : meetings) {
            if (mergedMeetings.empty()) {
                mergedMeetings.push_back(meeting);
            } else {
                int lastStart = mergedMeetings.back()[0];
                int lastEnd = mergedMeetings.back()[1];
                int currentStart = meeting[0];
                int currentEnd = meeting[1];

                if (currentStart <= lastEnd + 1) {
                    mergedMeetings.back()[1] = max(lastEnd, currentEnd);
                } else {
                    mergedMeetings.push_back(meeting);
                }
            }
        }

        int freeDays = 0;
        int previousEnd = 0;

        for (const vector<int>& meeting : mergedMeetings) {
            int start = meeting[0];
            int end = meeting[1];

            freeDays += start - previousEnd - 1;
            previousEnd = max(previousEnd, end);
        }

        freeDays += totalDays - previousEnd;

        return freeDays;
    }
};
