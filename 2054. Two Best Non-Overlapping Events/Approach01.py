class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        timeline = []
        for start, end, value in events:
            timeline.append((start, 1, value))  # Add the start of an event
            timeline.append((end + 1, -1, value))  # Add the end of an event
        timeline.sort()  # Sort by time
        
        maxEventValue = 0  # Maximum value of a single event seen so far
        maxCombinedValue = 0  # Best value of combining two events
        
        for time, eventType, eventValue in timeline:
            if eventType == 1:  # Start of an event
                maxCombinedValue = max(maxCombinedValue, maxEventValue + eventValue)
            elif eventType == -1:  # End of an event
                maxEventValue = max(maxEventValue, eventValue)
        
        return maxCombinedValue