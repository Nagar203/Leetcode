#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int first_min = INT_MAX;
        int second_min = INT_MAX;

        for(int i=0; i< prices.size(); i++){
            if(first_min > prices[i]){
                second_min = first_min;
                first_min = prices[i];
            }
            else if(second_min > prices[i]){
                second_min = prices[i];
            }
        }
        int result = money - (second_min + first_min);
        return result >=0? result: money;
    }
};