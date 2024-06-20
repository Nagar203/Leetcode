#include <algorithm>
#include <ranges>
#include <vector>

class Solution {
public:
    int maxDistance(std::vector<int>& position, int m) {
        std::ranges::sort(position);

        int left = 1;
        int right = position.back() - position.front();

        while (left < right) {
            const int mid = right - (right - left) / 2;
            if (numBalls(position, mid) >= m) // There're too many balls.
                left = mid;
            else // There're too few balls.
                right = mid - 1;
        }

        return left;
    }

private:
    int numBalls(const std::vector<int>& position, int force) {
        int balls = 0;
        int prev_position = -force;
        for (const int pos : position)
            if (pos - prev_position >= force) {
                ++balls;
                prev_position = pos;
            }
        return balls;
    }
};
