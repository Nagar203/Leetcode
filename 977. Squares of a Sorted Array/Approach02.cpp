#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        
        transform(nums.begin(), nums.end(), result.begin(), [](int x) { return x * x; });
        
        sort(result.begin(), result.end());
        
        return result;
    }
};
