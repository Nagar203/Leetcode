#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int result = money - (prices[0] + prices[1]);
        return result >=0 ? result: money;
    }
};