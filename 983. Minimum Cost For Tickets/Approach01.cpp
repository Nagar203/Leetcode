class Solution {
public:
    vector<int> memo;

    // Recursive helper function
    int solve(int index, const vector<int>& days, const vector<int>& costs) {
        // Base case: if all days are processed, return 0
        if (index >= days.size()) {
            return 0;
        }

        // If the result for this index is already computed, return it
        if (memo[index] != -1) {
            return memo[index];
        }

        // Option 1: Buy a 1-day pass
        int oneDayPass = costs[0] + solve(index + 1, days, costs);

        // Find the next index for 7-day pass
        int nextIndexForSevenDay = index;
        while (nextIndexForSevenDay < days.size() && days[nextIndexForSevenDay] < days[index] + 7) {
            ++nextIndexForSevenDay;
        }
        int sevenDayPass = costs[1] + solve(nextIndexForSevenDay, days, costs);

        // Find the next index for 30-day pass
        int nextIndexForThirtyDay = index;
        while (nextIndexForThirtyDay < days.size() && days[nextIndexForThirtyDay] < days[index] + 30) {
            ++nextIndexForThirtyDay;
        }
        int thirtyDayPass = costs[2] + solve(nextIndexForThirtyDay, days, costs);

        // Return and memoize the minimum cost
        memo[index] = min({oneDayPass, sevenDayPass, thirtyDayPass});
        return memo[index];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Initialize memoization array with -1
        memo.assign(days.size(), -1);
        return solve(0, days, costs);
    }
};