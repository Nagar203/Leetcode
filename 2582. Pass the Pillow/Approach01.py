from typing import *

class Solution:
    def passThePillow(self, num_people: int, time_elapsed: int) -> int:
        # Calculate the effective time within one complete cycle of passing the pillow
        cycle_time = (num_people - 1) * 2
        effective_time = time_elapsed % cycle_time

        # If the effective time is less than the number of people, the pillow is moving forward
        if effective_time < num_people:
            return 1 + effective_time

        # If the effective time is greater than or equal to the number of people, the pillow is moving backward
        return num_people - (effective_time - (num_people - 1))