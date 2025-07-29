class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        constexpr int maxBit = 30;
        vector<int> result(nums.size(), 1);
        vector<int> lastSeenBitIndex(maxBit);

        for (int currentIndex = nums.size() - 1; currentIndex >= 0; --currentIndex) {
            for (int bit = 0; bit < maxBit; ++bit) {
                if ((nums[currentIndex] >> bit) & 1)
                    lastSeenBitIndex[bit] = currentIndex;
                result[currentIndex] = max(result[currentIndex], lastSeenBitIndex[bit] - currentIndex + 1);
            }
        }

        return result;
    }
};
