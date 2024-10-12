#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Stores the `endTimes` of intervals.
        priority_queue<int, vector<int>, greater<>> endTimeMinHeap;

        // Sort intervals by starting time.
        sort(intervals.begin(), intervals.end());

        for (const vector<int>& interval : intervals) {
            // If there's no overlap, reuse the same group by removing the earliest ending interval.
            if (!endTimeMinHeap.empty() && interval[0] > endTimeMinHeap.top())
                endTimeMinHeap.pop();
            endTimeMinHeap.push(interval[1]);
        }

        // The size of the heap represents the number of groups required.
        return endTimeMinHeap.size();
    }
};
