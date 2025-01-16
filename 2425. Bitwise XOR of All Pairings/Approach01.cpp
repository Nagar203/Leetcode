#include <vector>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int resultXor = 0;

        // If nums2 has an odd number of elements, XOR all elements of nums1
        if (nums2.size() % 2 != 0) {
            for (int num : nums1) {
                resultXor ^= num;
            }
        }

        // If nums1 has an odd number of elements, XOR all elements of nums2
        if (nums1.size() % 2 != 0) {
            for (int num : nums2) {
                resultXor ^= num;
            }
        }

        return resultXor;
    }
};