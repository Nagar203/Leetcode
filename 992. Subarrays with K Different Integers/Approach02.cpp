#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> element_count;

        int start_smallest = 0;
        int end = 0;
        int start_largest = 0;

        int result = 0;

        while (end < n)
        {
            element_count[nums[end]]++;

            while (element_count.size() > k)
            {
                element_count[nums[start_smallest]]--;
                if (element_count[nums[start_smallest]] == 0)
                {
                    element_count.erase(nums[start_smallest]);
                }
                start_smallest++;
                start_largest = start_smallest;
            }

            while (element_count[nums[start_smallest]] > 1)
            {
                element_count[nums[start_smallest]]--;
                start_smallest++;
            }

            if (element_count.size() == k)
            {
                result += start_smallest - start_largest + 1;
            }

            end++;
        }

        return result;
    }
};
