from typing import List

class Solution:
    def countDays(self, totalDays: int, meetings: List[List[int]]) -> int:
        if not meetings:
            return totalDays

        meetings.sort()
        mergedMeetings = []

        for meeting in meetings:
            if not mergedMeetings:
                mergedMeetings.append(meeting)
            else:
                lastStart, lastEnd = mergedMeetings[-1]
                currentStart, currentEnd = meeting

                if currentStart <= lastEnd + 1:
                    mergedMeetings[-1] = [lastStart, max(lastEnd, currentEnd)]
                else:
                    mergedMeetings.append(meeting)

        freeDays = 0
        previousEnd = 0

        for start, end in mergedMeetings:
            freeDays += start - previousEnd - 1
            previousEnd = max(previousEnd, end)

        freeDays += totalDays - previousEnd

        return freeDays
