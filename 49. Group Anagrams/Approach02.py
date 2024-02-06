from typing import *
from collections import *

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = defaultdict(list)

        for s in strs:
            sorted_str = ''.join(sorted(s))
            groups[sorted_str].append(s)  # sorted_str working as key

        return list(groups.values())