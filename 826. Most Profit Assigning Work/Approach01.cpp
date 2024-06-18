#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int total_profit = 0;
        vector<pair<int, int>> jobs;

        // Pair up difficulty and profit for each job
        for (int i = 0; i < difficulty.size(); ++i)
            jobs.emplace_back(difficulty[i], profit[i]);

        // Sort jobs by difficulty and worker by their ability
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int job_index = 0;
        int max_profit_so_far = 0;

        // Iterate over each worker's ability
        for (const int ability : worker) {
            // Find the maximum profit job the worker can do
            while (job_index < jobs.size() &&
                   ability >= jobs[job_index].first) {
                max_profit_so_far =
                    max(max_profit_so_far, jobs[job_index].second);
                ++job_index;
            }
            // Add the maximum profit the worker can achieve to the total profit
            total_profit += max_profit_so_far;
        }

        return total_profit;
    }
};