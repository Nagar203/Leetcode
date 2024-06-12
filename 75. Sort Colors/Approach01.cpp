#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> data;
        
        for (int num : nums) {
            data[num]++;
        }
        
        int red = data[0];
        int white = data[1];
        int blue = data[2];
        
        nums.clear();
        
        nums.insert(nums.end(), red, 0);
        nums.insert(nums.end(), white, 1);
        nums.insert(nums.end(), blue, 2);
    }
};
