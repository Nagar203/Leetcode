#include <vector>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int totalItems = prices.size();
        for (int currentItem = 0; currentItem < totalItems - 1; currentItem++) {
            for (int nextItem = currentItem + 1; nextItem < totalItems; nextItem++) {
                if (nextItem > currentItem && prices[currentItem] >= prices[nextItem]) {
                    prices[currentItem] -= prices[nextItem];
                    break;
                }
            }
        }
        return prices;
    }
};