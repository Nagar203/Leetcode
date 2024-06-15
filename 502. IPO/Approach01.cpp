#include <bits/stdc++.h>

using namespace std;

struct T {
    int profit;
    int capital;
    T(int profit, int capital) : profit(profit), capital(capital) {}
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        auto compare_capital = [](const T& a, const T& b) {
            return a.capital > b.capital;
        };

        auto compare_profit = [](const T& a, const T& b) {
            return a.profit < b.profit;
        };

        priority_queue<T, vector<T>, decltype(compare_capital)> min_heap(compare_capital);
        priority_queue<T, vector<T>, decltype(compare_profit)> max_heap(compare_profit);

        for (int i = 0; i < capital.size(); ++i){
            min_heap.emplace(profits[i], capital[i]);
        }

        while (k--) {
            while (!min_heap.empty() && min_heap.top().capital <= w){
                max_heap.push(min_heap.top()), min_heap.pop();
            }
            if (max_heap.empty()){
                break;
            }
            w += max_heap.top().profit, max_heap.pop();
        }
        return w;
    }
};
