class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int minimumDifference = 24 * 60;  // Represents the minimum time difference in minutes
        int earliestTime = 24 * 60;  // The earliest time in the timePoints
        vector<bool> timeSeen(24 * 60, false);  // Bucket to track seen times (in minutes from 00:00)

        // Convert time points to minutes and mark them in the bucket
        for (const string& time : timePoints) {
            int currentTimeInMinutes = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
            earliestTime = min(earliestTime, currentTimeInMinutes);
            
            if (timeSeen[currentTimeInMinutes])  // If the time is already seen, the minimum difference is zero
                return 0;
                
            timeSeen[currentTimeInMinutes] = true;
        }

        int previousTime = earliestTime;  // Keep track of the previous time in the sorted order

        // Find the minimum difference between consecutive times
        for (int i = earliestTime + 1; i < timeSeen.size(); ++i) {
            if (timeSeen[i]) {
                minimumDifference = min(minimumDifference, i - previousTime);
                previousTime = i;
            }
        }

        // Compare the time difference between the first and last times considering the circular nature of the clock
        return min(minimumDifference, 24 * 60 - previousTime + earliestTime);
    }
};