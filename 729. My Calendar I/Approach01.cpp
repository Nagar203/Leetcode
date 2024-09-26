#include <unordered_set>
#include <vector>

class MyCalendar {
public:
    // Function to book a new event if there are no conflicts with existing
    // events
    bool book(int newStart, int newEnd) {
        // Check for any overlap with already booked events
        for (const auto& [existingStart, existingEnd] : calendar) {
            if (max(newStart, existingStart) < min(newEnd, existingEnd)){
                return false; // Overlap found, booking is not possible
            }
        }
        // No conflicts, book the event
        calendar.emplace_back(newStart, newEnd);
        return true;
    }

private:
    // Vector to store all the booked events as pairs of start and end times
    vector<pair<int, int>> calendar;
};