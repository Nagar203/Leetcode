#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int numberOfArrays(vector<int>& differences, int lower, int upper) {
    vector<long> prefixSum(differences.size() + 1);

    for (int i = 0; i < differences.size(); ++i)
      prefixSum[i + 1] = prefixSum[i] + differences[i];

    const long maxPrefix = *max_element(prefixSum.begin(), prefixSum.end());
    const long minPrefix = *min_element(prefixSum.begin(), prefixSum.end());

    return max(0L, (upper - lower) - (maxPrefix - minPrefix) + 1);
  }
};