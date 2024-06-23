from typing import List

class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        # Calculate the total number of satisfied customers without any changes
        total_satisfied = sum(c for i, c in enumerate(customers) if grumpy[i] == 0)
        additional_satisfied = 0
        current_window_satisfied = 0

        # Iterate over all customers
        for i, customer in enumerate(customers):
            # Add to the current window satisfied if the owner is grumpy
            if grumpy[i] == 1:
                current_window_satisfied += customer
            # Remove from the current window if the start of the window was grumpy
            if i >= X and grumpy[i - X] == 1:
                current_window_satisfied -= customers[i - X]
            # Update the maximum number of customers that can be satisfied
            additional_satisfied = max(additional_satisfied, current_window_satisfied)

        # Return the total satisfied customers
        return total_satisfied + additional_satisfied
