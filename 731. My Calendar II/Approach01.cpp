#include <vector>
#include <algorithm>

using namespace std;

class MyCalendarTwo {
public:
    // Function to book an event, ensuring no triple booking
    bool book(int newStart, int newEnd) {
        // Check for any overlap that would cause triple booking
        for (const auto& [overlapStart, overlapEnd] : overlapRanges) {
            if (max(newStart, overlapStart) < min(newEnd, overlapEnd))
                return false; // Triple booking found, return false
        }

        // Check existing events and add to overlaps if needed
        for (const auto& [existingStart, existingEnd] : bookedRanges) {
            int overlapStart = max(newStart, existingStart);
            int overlapEnd = min(newEnd, existingEnd);
            if (overlapStart < overlapEnd) {
                overlapRanges.emplace_back(overlapStart, overlapEnd);
            }
        }

        // Add the new booking to the list of booked ranges
        bookedRanges.emplace_back(newStart, newEnd);
        return true;
    }

private:
    // Vector to store all the booked events as pairs of start and end times
    vector<pair<int, int>> bookedRanges;

    // Vector to store overlapping ranges between events
    vector<pair<int, int>> overlapRanges;
};