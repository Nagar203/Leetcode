from typing import List

class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        all_ors = []
        prev_start = 0

        for num in arr:
            curr_end = len(all_ors)
            all_ors.append(num)
            for i in range(prev_start, curr_end):
                new_or = all_ors[i] | num
                if all_ors[-1] != new_or:
                    all_ors.append(new_or)
            prev_start = curr_end

        return len(set(all_ors))