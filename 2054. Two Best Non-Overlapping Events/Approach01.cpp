class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<tuple<int, int, int>> timeline;
        for (const auto& event : events) {
            int start = event[0];
            int end = event[1];
            int value = event[2];
            timeline.emplace_back(start, 1, value);  // Start of an event
            timeline.emplace_back(end + 1, -1, value);  // End of an event
        }
        sort(timeline.begin(), timeline.end());  // Sort by time
        
        int maxEventValue = 0;  // Maximum value of a single event seen so far
        int maxCombinedValue = 0;  // Best value of combining two events
        
        for (const auto& [time, eventType, eventValue] : timeline) {
            if (eventType == 1) {  // Start of an event
                maxCombinedValue = max(maxCombinedValue, maxEventValue + eventValue);
            } else if (eventType == -1) {  // End of an event
                maxEventValue = max(maxEventValue, eventValue);
            }
        }
        
        return maxCombinedValue;
    }
};