from typing import *

class MyCalendarTwo:

    def __init__(self):
        # List to store all booked events
        self.bookedRanges = []
        
        # List to store ranges where overlaps occur
        self.overlapRanges = []

    # Function to book an event, ensuring no triple booking
    def book(self, newStart, newEnd):
        # Check for any overlap that would cause triple booking
        for overlapStart, overlapEnd in self.overlapRanges:
            if max(newStart, overlapStart) < min(newEnd, overlapEnd):
                return False  # Triple booking found, return False

        # Check existing bookings and add to overlaps if needed
        for existingStart, existingEnd in self.bookedRanges:
            overlapStart = max(newStart, existingStart)
            overlapEnd = min(newEnd, existingEnd)
            if overlapStart < overlapEnd:
                self.overlapRanges.append((overlapStart, overlapEnd))

        # Add the new booking to the list of booked ranges
        self.bookedRanges.append((newStart, newEnd))
        return True