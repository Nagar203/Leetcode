from typing import *

class MyCalendar:
    def __init__(self):
        # Initialize an empty list to store the booked events
        self.bookedEvents = []

    # Function to book a new event if there are no conflicts with existing events
    def book(self, newStart, newEnd):
        # Check for any overlap with already booked events
        for existingStart, existingEnd in self.bookedEvents:
            if max(newStart, existingStart) < min(newEnd, existingEnd):
                return False  # Overlap found, booking is not possible
        
        # No conflicts, book the event
        self.bookedEvents.append((newStart, newEnd))
        return True