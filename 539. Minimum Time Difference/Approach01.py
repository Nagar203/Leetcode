from typing import *

class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        totalMinutesInDay = 24 * 60  # Total minutes in a day
        minimumDifference = totalMinutesInDay  # The minimum time difference in minutes
        earliestTime = totalMinutesInDay  # The earliest time in minutes
        timeSeen = [False] * totalMinutesInDay  # Bucket to track if a time has been seen

        # Convert time points to minutes and mark them in the timeSeen array
        for time in timePoints:
            currentTimeInMinutes = int(time[:2]) * 60 + int(time[3:])
            earliestTime = min(earliestTime, currentTimeInMinutes)

            if timeSeen[currentTimeInMinutes]:  # If the time has already been seen, return 0
                return 0

            timeSeen[currentTimeInMinutes] = True

        previousTime = earliestTime  # Keep track of the previous time in the sorted order

        # Find the minimum difference between consecutive times
        for i in range(earliestTime + 1, totalMinutesInDay):
            if timeSeen[i]:
                minimumDifference = min(minimumDifference, i - previousTime)
                previousTime = i

        # Compare the time difference between the first and last times considering the circular nature of the clock
        return min(minimumDifference, totalMinutesInDay - previousTime + earliestTime)