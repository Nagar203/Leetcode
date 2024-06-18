from typing import List

class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        total_profit = 0
        jobs = []

        # Pair up difficulty and profit for each job
        for i in range(len(difficulty)):
            jobs.append((difficulty[i], profit[i]))

        # Sort jobs by difficulty and worker by their ability
        jobs.sort()
        worker.sort()

        job_index = 0
        max_profit_so_far = 0

        # Iterate over each worker's ability
        for ability in worker:
            # Find the maximum profit job the worker can do
            while job_index < len(jobs) and ability >= jobs[job_index][0]:
                max_profit_so_far = max(max_profit_so_far, jobs[job_index][1])
                job_index += 1
            # Add the maximum profit the worker can achieve to the total profit
            total_profit += max_profit_so_far

        return total_profit