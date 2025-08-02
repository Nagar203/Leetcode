class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        vector<int> toSwap;
        unordered_map<int, int> itemCount;

        for (const int item : basket1)
            ++itemCount[item];
        for (const int item : basket2)
            --itemCount[item];

        for (const auto& [item, delta] : itemCount) {
            if (delta % 2 != 0) return -1; 
            for (int i = 0; i < abs(delta) / 2; ++i)
                toSwap.push_back(item);
        }

        int minElement = min(*min_element(basket1.begin(), basket1.end()), *min_element(basket2.begin(), basket2.end()));

        auto midIt = toSwap.begin() + toSwap.size() / 2;
        nth_element(toSwap.begin(), midIt, toSwap.end());

        return accumulate(
            toSwap.begin(), midIt, 0LL,
            [minElement](long long acc, int item) { return acc + min(2 * minElement, item); }
        );
    }
};