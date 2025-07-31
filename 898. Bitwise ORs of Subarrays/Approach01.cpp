class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        vector<int> all_ors;
        int prev_start = 0;

        for (const int num : arr) {
            int curr_end = all_ors.size();
            all_ors.push_back(num);
            for (int i = prev_start; i < curr_end; ++i) {
                int new_or = all_ors[i] | num;
                if (all_ors.back() != new_or) {
                    all_ors.push_back(new_or);
                }
            }
            prev_start = curr_end;
        }
        return unordered_set<int>(all_ors.begin(), all_ors.end()).size();
    }
};
