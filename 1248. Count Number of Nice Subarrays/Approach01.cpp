#include <vector>

class Solution {
public:
    int numberOfSubarrays(std::vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    int atMost(const std::vector<int>& nums, int k) {
        int count = 0;
        int left = 0;
        int odd_count = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] % 2 == 1) {
                odd_count++;
            }
            while (odd_count > k) {
                if (nums[left] % 2 == 1) {
                    odd_count--;
                }
                left++;
            }
            count += right - left + 1;
        }

        return count;
    }
};
