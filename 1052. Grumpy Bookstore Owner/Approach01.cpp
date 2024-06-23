class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int total_satisfied = 0;
        int additional_satisfied = 0;
        int current_window_satisfied = 0;

        for (int i = 0; i < customers.size(); ++i) {
            if (grumpy[i] == 0){
                total_satisfied += customers[i];
            }
            else{
                current_window_satisfied += customers[i];
            }
            if (i >= X && grumpy[i - X] == 1){
                current_window_satisfied -= customers[i - X];
            }
            additional_satisfied = max(additional_satisfied, current_window_satisfied);
        }

        return total_satisfied + additional_satisfied;
    }
};
