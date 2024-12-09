class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> results;
        int parityGroupId = 0;
        // parityGroupIds[i] := the group ID of the parity that nums[i] belongs to
        vector<int> parityGroupIds = {parityGroupId};

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] % 2 == nums[i - 1] % 2){
                ++parityGroupId;
            }
            parityGroupIds.push_back(parityGroupId);
        }

        for (const vector<int> query : queries) {
            const int startIndex = query[0];
            const int endIndex = query[1];
            results.push_back(parityGroupIds[startIndex] == parityGroupIds[endIndex]);
        }

        return results;
    }
};