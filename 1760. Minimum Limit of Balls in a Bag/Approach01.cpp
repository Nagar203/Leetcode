class Solution {
 public:
  int minimumSize(vector<int>& nums, int maxOperations) {
    int low = 1;
    int high = ranges::max(nums);

    while (low < high) {
      const int mid = (low + high) / 2;
      if (numOperations(nums, mid) <= maxOperations)
        high = mid;
      else
        low = mid + 1;
    }

    return low;
  }

 private:
  // Returns the number of operations required to make mid the penalty.
  int numOperations(const vector<int>& nums, int mid) {
    int totalOperations = 0;
    for (const int currentNum : nums)
      totalOperations += (currentNum - 1) / mid;
    return totalOperations;
  }
};