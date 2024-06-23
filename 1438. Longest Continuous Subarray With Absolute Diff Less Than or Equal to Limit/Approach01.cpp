#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int longest_length = 1;
        deque<int> min_queue;
        deque<int> max_queue;

        for (int left = 0, right = 0; right < nums.size(); ++right) {
            while (!min_queue.empty() && min_queue.back() > nums[right])
                min_queue.pop_back();
            min_queue.push_back(nums[right]);
            while (!max_queue.empty() && max_queue.back() < nums[right])
                max_queue.pop_back();
            max_queue.push_back(nums[right]);
            while (max_queue.front() - min_queue.front() > limit) {
                if (min_queue.front() == nums[left])
                    min_queue.pop_front();
                if (max_queue.front() == nums[left])
                    max_queue.pop_front();
                ++left;
            }
            longest_length = max(longest_length, right - left + 1);
        }

        return longest_length;
    }
};
