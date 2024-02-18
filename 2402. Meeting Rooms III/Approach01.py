from typing import *

class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort() 

        rooms_used_count = [0] * n
        last_available_info = [0] * n

        for meet in meetings:
            start, end = meet
            found = False

            early_end_room_time = float('inf')
            early_end_room = 0

            for room in range(n):
                if last_available_info[room] <= start:
                    found = True
                    last_available_info[room] = end
                    rooms_used_count[room] += 1
                    break

                if last_available_info[room] < early_end_room_time:
                    early_end_room = room
                    early_end_room_time = last_available_info[room]

            if not found:
                last_available_info[early_end_room] += (end - start)
                rooms_used_count[early_end_room] += 1

        result_room = -1
        max_use = 0
        for room in range(n):
            if rooms_used_count[room] > max_use:
                max_use = rooms_used_count[room]
                result_room = room

        return result_room
