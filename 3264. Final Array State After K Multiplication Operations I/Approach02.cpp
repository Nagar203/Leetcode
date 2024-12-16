class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap
        
        // Initialize the priority queue with initial values and indices
        for (int i = 0; i < nums.size(); ++i) {
            pq.push({nums[i], i});
        }
        
        while (k--) {
            // Get the minimum element and its index
            auto [val, idx] = pq.top();
            pq.pop();
            
            // Update the value and push it back
            val *= multiplier;
            pq.push({val, idx});
        }
        
        // Reconstruct the result array
        for (int i = 0; i < nums.size(); ++i) {
            auto [val, idx] = pq.top();
            pq.pop();
            nums[idx] = val;
        }
        
        return nums;
    }
};