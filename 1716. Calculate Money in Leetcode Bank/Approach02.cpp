#include <iostream>

using namespace std;

class Solution {
  public: int totalMoney(int n) {

        int num_weeks = n / 7;
        int remaining_days = n % 7;

        int total_money_weeks = (28 + 28 + 7 * (num_weeks - 1)) * num_weeks / 2;

        int start_day_money = num_weeks + 1;
        int end_day_money = num_weeks + remaining_days;
        int total_money_remaining = (start_day_money + end_day_money) * remaining_days / 2;

        return total_money_weeks + total_money_remaining;

  }
};