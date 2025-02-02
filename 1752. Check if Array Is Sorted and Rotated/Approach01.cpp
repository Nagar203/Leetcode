class Solution {
 public:
  bool check(vector<int>& nums) {
    const int size = nums.size();
    int rotationCount = 0;

    for (int i = 0; i < size; ++i)
      if (nums[i] > nums[(i + 1) % size] && ++rotationCount > 1)
        return false;

    return true;
  }
};
