from typing import *

class Solution:
    def countSeniors(self, details: List[str]) -> int:
        seniorCount = 0
        for detail in details:
            age = int(detail[-4:-2])
            if age > 60:
                seniorCount += 1
        return seniorCount
