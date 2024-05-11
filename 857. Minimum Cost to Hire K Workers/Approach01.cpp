#include <algorithm>
#include <queue>
#include <vector>

class Solution {
public:
    double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
        int n = quality.size();
        std::vector<std::pair<double, int>> workers;

        for (int i = 0; i < n; ++i) {
            workers.push_back(
                {static_cast<double>(wage[i]) / quality[i], quality[i]});
        }

        std::sort(workers.begin(), workers.end());
        std::priority_queue<int> max_heap;
        double min_cost = std::numeric_limits<double>::infinity();
        double total_quality = 0;

        for (auto [ratio, q] : workers) {
            total_quality += q;
            max_heap.push(q);

            if (max_heap.size() > k) {
                total_quality -= max_heap.top();
                max_heap.pop();
            }

            if (max_heap.size() == k) {
                min_cost = std::min(min_cost, ratio * total_quality);
            }
        }

        return min_cost;
    }
};
