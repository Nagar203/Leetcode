class Solution:
    def mincostTickets(self, days: list[int], costs: list[int]) -> int:
        # Memoization array
        memo = [-1] * len(days)

        # Recursive helper function
        def solve(index: int) -> int:
            # Base case: if all days are processed, return 0
            if index >= len(days):
                return 0

            # If the result for this index is already computed, return it
            if memo[index] != -1:
                return memo[index]

            # Option 1: Buy a 1-day pass
            oneDayPass = costs[0] + solve(index + 1)

            # Find the next index for 7-day pass
            nextIndexForSevenDay = index
            while nextIndexForSevenDay < len(days) and days[nextIndexForSevenDay] < days[index] + 7:
                nextIndexForSevenDay += 1
            sevenDayPass = costs[1] + solve(nextIndexForSevenDay)

            # Find the next index for 30-day pass
            nextIndexForThirtyDay = index
            while nextIndexForThirtyDay < len(days) and days[nextIndexForThirtyDay] < days[index] + 30:
                nextIndexForThirtyDay += 1
            thirtyDayPass = costs[2] + solve(nextIndexForThirtyDay)

            # Return and memoize the minimum cost
            memo[index] = min(oneDayPass, sevenDayPass, thirtyDayPass)
            return memo[index]

        # Start the recursive process from the first index
        return solve(0)