#include <vector>
#include <algorithm>

using namespace std;

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0; 
        int j = n-1;
        int k = n-1;
        vector<int> result(n);
        while(k>=0){
            int a = nums[i]*nums[i];
            int b = nums[j]*nums[j];
            if(a > b){
                result[k] = a;
                i++;
            }
            else{
                result[k] = b;
                j--;
            }
            k--;
        }
        
        return result;
    }
};
