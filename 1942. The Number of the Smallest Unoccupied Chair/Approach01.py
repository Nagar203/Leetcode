import heapq

class Solution:
    def smallestChair(self, times, targetFriend):
        nextAvailableChair = 0
        availableChairs = []
        occupiedChairs = []

        # Append friend indices to the times list
        for i in range(len(times)):
            times[i].append(i)

        # Sort times by arrival time
        times.sort()

        for arrivalTime, leavingTime, friendIndex in times:
            # Free up chairs for friends who have left by the current arrival time
            while occupiedChairs and occupiedChairs[0][0] <= arrivalTime:
                _, chairNumber = heapq.heappop(occupiedChairs)
                heapq.heappush(availableChairs, chairNumber)

            # If the current friend is the target friend
            if friendIndex == targetFriend:
                return availableChairs[0] if availableChairs else nextAvailableChair

            # Assign the next available chair
            if availableChairs:
                chairNumber = heapq.heappop(availableChairs)
            else:
                chairNumber = nextAvailableChair
                nextAvailableChair += 1

            heapq.heappush(occupiedChairs, (leavingTime, chairNumber))

        raise Exception("This shouldn't be reached")