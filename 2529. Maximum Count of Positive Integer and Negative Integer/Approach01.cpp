class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negCount = 0;
        int zeros = 0;
        for(int &num: nums){
            if(num<0){
                ++negCount;
            }
            if(num==0){
                ++zeros;
            }
        }
        int n = nums.size();
        return max(n - zeros - negCount, negCount);
    }
};