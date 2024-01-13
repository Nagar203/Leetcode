from typing import *
import collections

class Solution:
    def minSteps(self, s: str, t: str) -> int:
        return (Counter(t)-Counter(s)).total()