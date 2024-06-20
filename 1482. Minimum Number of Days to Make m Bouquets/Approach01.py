from typing import List

class Solution:
    def minDays(self, bloom_day: List[int], m: int, k: int) -> int:
        # Check if it's possible to make m bouquets with the given flowers
        if len(bloom_day) < m * k:
            return -1

        def get_bouquet_count(waiting_days: int) -> int:
            bouquet_count = 0  # To store the number of bouquets we can make
            required_flowers = 0  # To count the current contiguous flowers that have bloomed

            for day in bloom_day:
                if day <= waiting_days:
                    required_flowers += 1
                    # When we have enough flowers to make one bouquet
                    if required_flowers == k:
                        bouquet_count += 1
                        required_flowers = 0  # Reset the counter for the next bouquet
                else:
                    required_flowers = 0  # Reset the counter if the flower hasn't bloomed yet

            return bouquet_count

        # Set the initial bounds for binary search
        l = min(bloom_day)  # Minimum possible days to wait (the earliest bloom day)
        r = max(bloom_day)  # Maximum possible days to wait (the latest bloom day)

        # Perform binary search to find the minimum number of days
        while l < r:
            mid = (l + r) // 2  # Calculate the midpoint

            # Check if we can make at least m bouquets with mid days of waiting
            if get_bouquet_count(mid) >= m:
                r = mid  # Try a smaller number of days
            else:
                l = mid + 1  # Try a larger number of days

        # After binary search, l should be the minimum number of days needed
        return l if get_bouquet_count(l) >= m else -1