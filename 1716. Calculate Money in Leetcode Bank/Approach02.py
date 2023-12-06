from typing import *

class Solution:
    def totalMoney(self, n: int) -> int:
        num_weeks = n // 7
        remaining_days = n % 7

        total_money_weeks = (28 + 28 + 7 * (num_weeks - 1)) * num_weeks // 2

        start_day_money = num_weeks + 1
        end_day_money = num_weeks + remaining_days
        total_money_remaining = (start_day_money + end_day_money) * remaining_days // 2

        return total_money_weeks + total_money_remaining