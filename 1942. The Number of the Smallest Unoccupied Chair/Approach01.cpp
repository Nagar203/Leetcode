#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int nextAvailableChair = 0;
        priority_queue<int, vector<int>, greater<>> availableChairs;
        using ChairEvent = pair<int, int>;  // (leavingTime, chairNumber)
        priority_queue<ChairEvent, vector<ChairEvent>, greater<>> occupiedChairs;

        // Append friend indices to the times
        for (int i = 0; i < times.size(); ++i) {
            times[i].push_back(i);
        }

        // Sort times by arrival time
        sort(times.begin(), times.end());

        for (const vector<int>& time : times) {
            int arrivalTime = time[0];
            int leavingTime = time[1];
            int friendIndex = time[2];

            // Free up chairs for friends who have left by the current arrival time
            while (!occupiedChairs.empty() && occupiedChairs.top().first <= arrivalTime) {
                availableChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }

            // If the current friend is the target friend
            if (friendIndex == targetFriend) {
                return availableChairs.empty() ? nextAvailableChair : availableChairs.top();
            }

            // Assign the next available chair
            if (availableChairs.empty()) {
                occupiedChairs.emplace(leavingTime, nextAvailableChair++);
            } else {
                occupiedChairs.emplace(leavingTime, availableChairs.top());
                availableChairs.pop();
            }
        }

        throw;  // This shouldn't be reached
    }
};