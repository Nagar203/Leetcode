#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minDays(std::vector<int>& bloom_day, int m, int k) {
        // Check if it's possible to make m bouquets with the given flowers
        if (static_cast<long long>(m) * k > bloom_day.size()) {
            return -1;
        }

        // Helper function to calculate the number of bouquets that can be made after `waiting_days`
        auto get_bouquet_count = [&bloom_day, k](int waiting_days) -> int {
            int bouquet_count = 0;  // To store the number of bouquets we can make
            int required_flowers = 0;  // To count the current contiguous flowers that have bloomed

            for (int day : bloom_day) {
                if (day <= waiting_days) {
                    required_flowers += 1;
                    // When we have enough flowers to make one bouquet
                    if (required_flowers == k) {
                        bouquet_count += 1;
                        required_flowers = 0;  // Reset the counter for the next bouquet
                    }
                } else {
                    required_flowers = 0;  // Reset the counter if the flower hasn't bloomed yet
                }
            }
            return bouquet_count;
        };

        // Set the initial bounds for binary search
        int l = *std::min_element(bloom_day.begin(), bloom_day.end());  // Minimum possible days to wait (the earliest bloom day)
        int r = *std::max_element(bloom_day.begin(), bloom_day.end());  // Maximum possible days to wait (the latest bloom day)

        // Perform binary search to find the minimum number of days
        while (l < r) {
            int mid = (l + r) / 2;  // Calculate the midpoint

            // Check if we can make at least m bouquets with mid days of waiting
            if (get_bouquet_count(mid) >= m) {
                r = mid;  // Try a smaller number of days
            } else {
                l = mid + 1;  // Try a larger number of days
            }
        }

        // After binary search, l should be the minimum number of days needed
        return get_bouquet_count(l) >= m ? l : -1;
    }
};