class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diffArray(nums.size() + 1); 
        int currentSum = 0;  
        int queryIndex = 0;  
        for (int i = 0; i < nums.size(); ++i) {
            while (currentSum + diffArray[i] < nums[i]) {
                if (queryIndex == queries.size())
                    return -1; 
                const int left = queries[queryIndex][0];
                const int right = queries[queryIndex][1];
                const int incrementValue = queries[queryIndex][2];
                ++queryIndex;
                if (right < i)
                    continue; 
                diffArray[max(left, i)] += incrementValue;
                diffArray[right + 1] -= incrementValue;
            }
            currentSum += diffArray[i]; 
        }
        return queryIndex;
    }
};