from typing import List
from collections import defaultdict

class Solution:
    # Helper function to get the frequency dictionary of elements in a list
    def get_dict(self, data: List[int]) -> dict:
        data_dict = defaultdict(int)
        for t in data:
            data_dict[t] += 1
        return data_dict

    # Function to check if target can be made equal to arr by shuffling
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        # Get frequency dictionaries for both target and arr
        target_dict = self.get_dict(target)
        arr_dict = self.get_dict(arr)

        # Iterate through the frequency dictionary of target
        for key, val in target_dict.items():
            # If key is not present in arr or its count does not match in both dictionaries, return False
            if key not in arr_dict or arr_dict[key] != val:
                return False
        
        # If all keys match with their counts, return True
        return True
